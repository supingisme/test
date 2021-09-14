
#include <aio.h>

int lio_listio(int mode, struct aiocb *const aiocb_list[],
               int nitems, struct sigevent *sevp);

