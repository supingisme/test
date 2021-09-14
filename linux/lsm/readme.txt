 内核安全模块 Linux Security Modules

struct lsm_info {
	const char *name;	/* Required. */
	enum lsm_order order;	/* Optional: default is LSM_ORDER_MUTABLE */
	unsigned long flags;	/* Optional: flags describing LSM */
	int *enabled;		/* Optional: controlled by CONFIG_LSM */
	int (*init)(void);	/* Required. */
	struct lsm_blob_sizes *blobs; /* Optional: for blob sharing. */
};



int __init early_security_init(void)
{ //安全初始化 一系列的  hash 表
	int i;
	struct hlist_head *list = (struct hlist_head *) &security_hook_heads;
	struct lsm_info *lsm;

	for (i = 0; i < sizeof(security_hook_heads) / sizeof(struct hlist_head);
	     i++)
		INIT_HLIST_HEAD(&list[i]);

	for (lsm = __start_early_lsm_info; lsm < __end_early_lsm_info; lsm++) {
		if (!lsm->enabled)
			lsm->enabled = &lsm_enabled_true;
		prepare_lsm(lsm);
		initialize_lsm(lsm);
	}

	return 0;
}
