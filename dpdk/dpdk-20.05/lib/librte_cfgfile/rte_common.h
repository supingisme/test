#ifndef __rte_common_h
#define __rte_common_h 1


#define __rte_unused __attribute__((unused))
#define __rte_format_printf(x,y) __attribute__((__format__ (printf, x, y)))
#define __rte_aligned(x)	__attribute__((aligned(x)))

#define strlcpy rte_strlcpy
#define strlcat rte_strlcat


#define	RTE_DIM(a)	(sizeof (a) / sizeof ((a)[0]))


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

/**
 * @internal
 * DPDK-specific version of strlcat for systems without
 * libc or libbsd copies of the function
 */
static inline size_t
rte_strlcat(char *dst, const char *src, size_t size)
{
	size_t l = strnlen(dst, size);
	if (l < size)
		return l + rte_strlcpy(&dst[l], src, size - l);
	return l + strlen(src);
}


#endif
