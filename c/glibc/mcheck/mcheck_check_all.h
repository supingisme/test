#include <mcheck.h>

//heap consistency checking
//int mcheck(void (*abortfunc)(enum mcheck_status mstatus));

//int mcheck_pedantic(void (*abortfunc)(enum mcheck_status mstatus));

//
/* Force check of all blocks now.  */
void mcheck_check_all(void);

//enum mcheck_status mprobe(void *ptr);


