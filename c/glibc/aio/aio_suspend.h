
#include <aio.h>

int aio_suspend(const struct aiocb * const aiocb_list[],
                int nitems, const struct timespec *timeout);

