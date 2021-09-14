#include <mcheck.h>

//heap consistency checking
//int mcheck(void (*abortfunc)(enum mcheck_status mstatus));

//比 mcheck 更低效，但更详细的
/* Similar to `mcheck' but performs checks for all block whenever one of
   the memory handling functions is called.  This can be very slow.  */
int mcheck_pedantic(void (*abortfunc)(enum mcheck_status mstatus));

//void mcheck_check_all(void);
//
//enum mcheck_status mprobe(void *ptr);


