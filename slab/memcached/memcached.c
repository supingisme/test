#include "memcached.h"


volatile int slab_rebalance_signal;
struct slab_rebalance slab_rebal;

/** exported globals **/
struct stats stats;
struct stats_state stats_state;

struct settings settings;

volatile rel_time_t current_time;

