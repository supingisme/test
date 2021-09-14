#ifndef __cmdline_common_h
#define __cmdline_common_h 1

#define __rte_unused __attribute__((unused))
#define __rte_format_printf(x,y) __attribute__((__format__ (printf, x, y)))
#define __rte_aligned(x)	__attribute__((aligned(x)))

#define strlcpy rte_strlcpy

/**
 * @internal
 * DPDK-specific version of strlcpy for systems without
 * libc or libbsd copies of the function
 */
static inline size_t
rte_strlcpy(char *dst, const char *src, size_t size)
{
	return (size_t)snprintf(dst, size, "%s", src);
}



#endif
