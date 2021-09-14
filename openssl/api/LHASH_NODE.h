/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
typedef struct lhash_node_st
{
    void *data;
    struct lhash_node_st *next;
#ifndef OPENSSL_NO_HASH_COMP
    unsigned long hash;
#endif
} LHASH_NODE;

typedef struct lhash_st
{
    LHASH_NODE **b;
    LHASH_COMP_FN_TYPE comp;
    LHASH_HASH_FN_TYPE hash;
    unsigned int num_nodes;
    unsigned int num_alloc_nodes;
    unsigned int p;
    unsigned int pmax;
    unsigned long up_load; /* load times 256 */
    unsigned long down_load; /* load times 256 */
    unsigned long num_items;
    unsigned long num_expands;
    unsigned long num_expand_reallocs;
    unsigned long num_contracts;
    unsigned long num_contract_reallocs;
    unsigned long num_hash_calls;
    unsigned long num_comp_calls;
    unsigned long num_insert;
    unsigned long num_replace;
    unsigned long num_delete;
    unsigned long num_no_delete;
    unsigned long num_retrieve;
    unsigned long num_retrieve_miss;
    unsigned long num_hash_comps;
    int error;
} LHASH;



_LHASH *lh_new(LHASH_HASH_FN_TYPE h, LHASH_COMP_FN_TYPE c);
void lh_free(_LHASH *lh);
void *lh_insert(_LHASH *lh, void *data);
void *lh_delete(_LHASH *lh, const void *data);
void *lh_retrieve(_LHASH *lh, const void *data);
void lh_doall(_LHASH *lh, LHASH_DOALL_FN_TYPE func);
void lh_doall_arg(_LHASH *lh, LHASH_DOALL_ARG_FN_TYPE func, void *arg);
unsigned long lh_strhash(const char *c);
unsigned long lh_num_items(const _LHASH *lh);

# ifndef OPENSSL_NO_FP_API
void lh_stats(const _LHASH *lh, FILE *out);
void lh_node_stats(const _LHASH *lh, FILE *out);
void lh_node_usage_stats(const _LHASH *lh, FILE *out);
# endif

# ifndef OPENSSL_NO_BIO
void lh_stats_bio(const _LHASH *lh, BIO *out);
void lh_node_stats_bio(const _LHASH *lh, BIO *out);
void lh_node_usage_stats_bio(const _LHASH *lh, BIO *out);
# endif

