
/*
 * default log function
 */
static ssize_t
console_log_write(__rte_unused void *c, const char *buf, size_t size)
{
	ssize_t ret;

	/* write on stdout */
	ret = fwrite(buf, 1, size, stdout);
	fflush(stdout);

	/* Syslog error levels are from 0 to 7, so subtract 1 to convert */
	syslog(rte_log_cur_msg_loglevel() - 1, "%.*s", (int)size, buf);

	return ret;
}

static cookie_io_functions_t console_log_func = {
	.write = console_log_write,
};



static cookie_io_functions_t console_log_func = {
	.write = console_log_write,
};

/*
 * set the log to default function, called during eal init process,
 * once memzones are available.
 */
int
rte_eal_log_init(const char *id, int facility)
{
	FILE *log_stream;

    //test/c/glibc/stdio/fopencookie 查看fopencookie示例
	log_stream = fopencookie(NULL, "w+", console_log_func);
	if (log_stream == NULL)
		return -1;

	openlog(id, LOG_NDELAY | LOG_PID, facility);

	eal_log_set_default(log_stream);

	return 0;
}

/*
 * Called by environment-specific initialization functions.
 */
void
eal_log_set_default(FILE *default_log)
{
	default_log_stream = default_log;

#if RTE_LOG_DP_LEVEL >= RTE_LOG_DEBUG
	RTE_LOG(NOTICE, EAL,
		"Debug dataplane logs available - lower performance\n");
#endif
}

