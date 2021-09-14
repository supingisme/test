#include <mcheck.h>

//heap consistency checking
//int mcheck(void (*abortfunc)(enum mcheck_status mstatus));

//int mcheck_pedantic(void (*abortfunc)(enum mcheck_status mstatus));

//void mcheck_check_all(void);

/* Check for aberrations(脱离常规; 反常现象; 异常行为;) in a particular malloc'd block.  You must have
   called `mcheck' already.  These are the same checks that `mcheck' does
   when you free or reallocate a block.  */
enum mcheck_status mprobe(void *ptr);



