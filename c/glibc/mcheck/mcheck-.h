#include <mcheck.h>

//heap consistency checking

/* Activate a standard collection of debugging hooks.  This must be called
   before `malloc' is ever called.  ABORTFUNC is called with an error code
   (see enum above) when an inconsistency is detected.  If ABORTFUNC is
   null, the standard function prints on stderr and then calls `abort'.  */
int mcheck(void (*abortfunc)(enum mcheck_status mstatus));

//int mcheck_pedantic(void (*abortfunc)(enum mcheck_status mstatus));

//void mcheck_check_all(void);

//enum mcheck_status mprobe(void *ptr);

