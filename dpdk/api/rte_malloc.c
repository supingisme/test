/*
 *  * Allocate memory on default heap.
 *   */
void *
rte_malloc(const char *type, size_t size, unsigned align)
{
	return rte_malloc_socket(type, size, align, SOCKET_ID_ANY);
}

//3.4.2.	对齐和NUMA限制
//接口rte_malloc()传入一个对齐参数，该参数用于请求在该值的倍数上对齐的内存区域(这个值必须是2的幂次)。
//
//在支持NUMA的系统上，对rte_malloc()接口调用将返回在调用函数的Core所在的插槽上分配的内存。DPDK还提供了另一组API，以允许在指定NUMA插槽上直接显式分配内存，或者分配另一个NUAM插槽上的内存。
//
