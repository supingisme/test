#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/time.h>

#include "slabs.h"

/* Slab sizing definitions. */
#define POWER_SMALLEST 1
#define POWER_LARGEST  256 /* actual cap is 255 */
#define SLAB_GLOBAL_PAGE_POOL 0 /* magic slab class for storing pages for reassignment */
#define CHUNK_ALIGN_BYTES 8
/* slab class max is a 6-bit number, -1. */
#define MAX_NUMBER_OF_SLAB_CLASSES (63 + 1)

enum protocol {
    ascii_prot = 3, /* arbitrary value. */
    binary_prot,
    negotiating_prot /* Discovering the protocol */
};


/* TODO: Move to slabs.h? */
extern volatile int slab_rebalance_signal;

struct slab_rebalance {
    void *slab_start;
    void *slab_end;
    void *slab_pos;
    int s_clsid;
    int d_clsid;
    uint32_t busy_items;
    uint32_t rescues;
    uint32_t evictions_nomem;
    uint32_t inline_reclaim;
    uint32_t chunk_rescues;
    uint32_t busy_deletes;
    uint32_t busy_loops;
    uint8_t done;
    uint8_t *completed;
};

extern struct slab_rebalance slab_rebal;



/**
 * Global "state" stats. Reflects state that shouldn't be wiped ever.
 * Ordered for some cache line locality for commonly updated counters.
 */
struct stats_state {
    uint64_t      curr_items;
    uint64_t      curr_bytes;
    uint64_t      curr_conns;
    uint64_t      hash_bytes;       /* size used for hash tables */
    unsigned int  conn_structs;
    unsigned int  reserved_fds;
    unsigned int  hash_power_level; /* Better hope it's not over 9000 */
    bool          hash_is_expanding; /* If the hash table is being expanded */
    bool          accepting_conns;  /* whether we are currently accepting */
    bool          slab_reassign_running; /* slab reassign in progress */
    bool          lru_crawler_running; /* crawl in progress */
};


/**
 * Global stats. Only resettable stats should go into this structure.
 */
struct stats {
    uint64_t      total_items;
    uint64_t      total_conns;
    uint64_t      rejected_conns;
    uint64_t      malloc_fails;
    uint64_t      listen_disabled_num;
    uint64_t      slabs_moved;       /* times slabs were moved around */
    uint64_t      slab_reassign_rescues; /* items rescued during slab move */
    uint64_t      slab_reassign_evictions_nomem; /* valid items lost during slab move */
    uint64_t      slab_reassign_inline_reclaim; /* valid items lost during slab move */
    uint64_t      slab_reassign_chunk_rescues; /* chunked-item chunks recovered */
    uint64_t      slab_reassign_busy_items; /* valid temporarily unmovable */
    uint64_t      slab_reassign_busy_deletes; /* refcounted items killed */
    uint64_t      lru_crawler_starts; /* Number of item crawlers kicked off */
    uint64_t      lru_maintainer_juggles; /* number of LRU bg pokes */
    uint64_t      time_in_listen_disabled_us;  /* elapsed time in microseconds while server unable to process new connections */
    uint64_t      log_worker_dropped; /* logs dropped by worker threads */
    uint64_t      log_worker_written; /* logs written by worker threads */
    uint64_t      log_watcher_skipped; /* logs watchers missed */
    uint64_t      log_watcher_sent; /* logs sent to watcher buffers */
#ifdef EXTSTORE
    uint64_t      extstore_compact_lost; /* items lost because they were locked */
    uint64_t      extstore_compact_rescues; /* items re-written during compaction */
    uint64_t      extstore_compact_skipped; /* unhit items skipped during compaction */
#endif
#ifdef TLS
    uint64_t      ssl_handshake_errors; /* TLS failures at accept/handshake time */
    uint64_t      ssl_new_sessions; /* successfully negotiated new (non-reused) TLS sessions */
#endif
    struct timeval maxconns_entered;  /* last time maxconns entered */
};

 
/** exported globals **/
extern struct stats stats;
extern struct stats_state stats_state;

extern struct settings settings;



/* Inlined from memcached.h - should go into sub header */
typedef unsigned int rel_time_t;


#define ITEM_LINKED 1
#define ITEM_CAS 2

/* temp */
#define ITEM_SLABBED 4

/* Item was fetched at least once in its lifetime */
#define ITEM_FETCHED 8
/* Appended on fetch, removed on LRU shuffling */
#define ITEM_ACTIVE 16
/* If an item's storage are chained chunks. */
#define ITEM_CHUNKED 32
#define ITEM_CHUNK 64
/* ITEM_data bulk is external to item */
#define ITEM_HDR 128
/* additional 4 bytes for item client flags */
#define ITEM_CFLAGS 256
/* item has sent out a token already */
#define ITEM_TOKEN_SENT 512
/* reserved, in case tokens should be a 2-bit count in future */
#define ITEM_TOKEN_RESERVED 1024
/* if item has been marked as a stale value */
#define ITEM_STALE 2048

/**
 * Structure for storing items within memcached.
 */
typedef struct _stritem {
    /* Protected by LRU locks */
    struct _stritem *next;
    struct _stritem *prev;
    /* Rest are protected by an item lock */
    struct _stritem *h_next;    /* hash chain next */
    rel_time_t      time;       /* least recent access */
    rel_time_t      exptime;    /* expire time */
    int             nbytes;     /* size of data */
    unsigned short  refcount;
    uint16_t        it_flags;   /* ITEM_* above */
    uint8_t         slabs_clsid;/* which slab class we're in */
    uint8_t         nkey;       /* key length, w/terminating null and padding */
    /* this odd type prevents type-punning issues when we do
     * the little shuffle to save space when not using CAS. */
    union {
        uint64_t cas;
        char end;
    } data[];
    /* if it_flags & ITEM_CAS we have 8 bytes CAS */
    /* then null-terminated key */
    /* then " flags length\r\n" (no terminating null) */
    /* then data with terminating \r\n (no terminating null; it's binary!) */
} item;


/* Header when an item is actually a chunk of another item. */
typedef struct _strchunk {
    struct _strchunk *next;     /* points within its own chain. */
    struct _strchunk *prev;     /* can potentially point to the head. */
    struct _stritem  *head;     /* always points to the owner chunk */
    int              size;      /* available chunk space in bytes */
    int              used;      /* chunk space used */
    int              nbytes;    /* used. */
    unsigned short   refcount;  /* used? */
    uint16_t         it_flags;  /* ITEM_* above. */
    uint8_t          slabs_clsid; /* Same as above. */
    uint8_t          orig_clsid; /* For obj hdr chunks slabs_clsid is fake. */
    char data[];
} item_chunk;



/* When adding a setting, be sure to update process_stat_settings */
/**
 * Globally accessible settings as derived from the commandline.
 */
struct settings {
    size_t maxbytes;
    int maxconns;
    int port;
    int udpport;
    char *inter;
    int verbose;
    rel_time_t oldest_live; /* ignore existing items older than this */
    uint64_t oldest_cas; /* ignore existing items with CAS values lower than this */
    int evict_to_free;
    char *socketpath;   /* path to unix socket if using local socket */
    char *auth_file;    /* path to user authentication file */
    int access;  /* access mask (a la chmod) for unix domain socket */
    double factor;          /* chunk size growth factor */
    int chunk_size;
    int num_threads;        /* number of worker (without dispatcher) libevent threads to run */
    int num_threads_per_udp; /* number of worker threads serving each udp socket */
    char prefix_delimiter;  /* character that marks a key prefix (for stats) */
    int detail_enabled;     /* nonzero if we're collecting detailed stats */
    int reqs_per_event;     /* Maximum number of io to process on each
                               io-event. */
    bool use_cas;
    enum protocol binding_protocol;
    int backlog;
    int item_size_max;        /* Maximum item size */
    int slab_chunk_size_max;  /* Upper end for chunks within slab pages. */
    int slab_page_size;     /* Slab's page units. */
    volatile sig_atomic_t sig_hup;  /* a HUP signal was received but not yet handled */
    bool sasl;              /* SASL on/off */
    bool maxconns_fast;     /* Whether or not to early close connections */
    bool lru_crawler;        /* Whether or not to enable the autocrawler thread */
    bool lru_maintainer_thread; /* LRU maintainer background thread */
    bool lru_segmented;     /* Use split or flat LRU's */
    bool slab_reassign;     /* Whether or not slab reassignment is allowed */
    int slab_automove;     /* Whether or not to automatically move slabs */
    double slab_automove_ratio; /* youngest must be within pct of oldest */
    unsigned int slab_automove_window; /* window mover for algorithm */
    int hashpower_init;     /* Starting hash power level */
    bool shutdown_command; /* allow shutdown command */
    int tail_repair_time;   /* LRU tail refcount leak repair time */
    bool flush_enabled;     /* flush_all enabled */
    bool dump_enabled;      /* whether cachedump/metadump commands work */
    char *hash_algorithm;     /* Hash algorithm in use */
    int lru_crawler_sleep;  /* Microsecond sleep between items */
    uint32_t lru_crawler_tocrawl; /* Number of items to crawl per run */
    int hot_lru_pct; /* percentage of slab space for HOT_LRU */
    int warm_lru_pct; /* percentage of slab space for WARM_LRU */
    double hot_max_factor; /* HOT tail age relative to COLD tail */
    double warm_max_factor; /* WARM tail age relative to COLD tail */
    int crawls_persleep; /* Number of LRU crawls to run before sleeping */
    bool temp_lru; /* TTL < temporary_ttl uses TEMP_LRU */
    uint32_t temporary_ttl; /* temporary LRU threshold */
    int idle_timeout;       /* Number of seconds to let connections idle */
    unsigned int logger_watcher_buf_size; /* size of logger's per-watcher buffer */
    unsigned int logger_buf_size; /* size of per-thread logger buffer */
    unsigned int read_buf_mem_limit; /* total megabytes allowable for net buffers */
    bool drop_privileges;   /* Whether or not to drop unnecessary process privileges */
    bool watch_enabled; /* allows watch commands to be dropped */
    bool relaxed_privileges;   /* Relax process restrictions when running testapp */
#ifdef EXTSTORE
    unsigned int ext_io_threadcount; /* number of IO threads to run. */
    unsigned int ext_page_size; /* size in megabytes of storage pages. */
    unsigned int ext_item_size; /* minimum size of items to store externally */
    unsigned int ext_item_age; /* max age of tail item before storing ext. */
    unsigned int ext_low_ttl; /* remaining TTL below this uses own pages */
    unsigned int ext_recache_rate; /* counter++ % recache_rate == 0 > recache */
    unsigned int ext_wbuf_size; /* read only note for the engine */
    unsigned int ext_compact_under; /* when fewer than this many pages, compact */
    unsigned int ext_drop_under; /* when fewer than this many pages, drop COLD items */
    double ext_max_frag; /* ideal maximum page fragmentation */
    double slab_automove_freeratio; /* % of memory to hold free as buffer */
    bool ext_drop_unread; /* skip unread items during compaction */
    /* per-slab-class free chunk limit */
    unsigned int ext_free_memchunks[MAX_NUMBER_OF_SLAB_CLASSES];
#endif
#ifdef TLS
    bool ssl_enabled; /* indicates whether SSL is enabled */
    SSL_CTX *ssl_ctx; /* holds the SSL server context which has the server certificate */
    char *ssl_chain_cert; /* path to the server SSL chain certificate */
    char *ssl_key; /* path to the server key */
    int ssl_verify_mode; /* client certificate verify mode */
    int ssl_keyformat; /* key format , defult is PEM */
    char *ssl_ciphers; /* list of SSL ciphers */
    char *ssl_ca_cert; /* certificate with CAs. */
    rel_time_t ssl_last_cert_refresh_time; /* time of the last server certificate refresh */
    unsigned int ssl_wbuf_size; /* size of the write buffer used by ssl_sendmsg method */
    bool ssl_session_cache; /* enable SSL server session caching */
#endif
};


extern volatile rel_time_t current_time;
 
