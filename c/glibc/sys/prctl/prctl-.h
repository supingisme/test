#include <sys/prctl.h>

int prctl(int option, unsigned long arg2, unsigned long arg3,
         unsigned long arg4, unsigned long arg5);


#ifdef __rtoax_study
void __rtoax_study_nginx_prctl()
{
#if (NGX_HAVE_PR_SET_KEEPCAPS && NGX_HAVE_CAPABILITIES)
//    if (ccf->transparent && ccf->user) {
        if (prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0) == -1) {
            ngx_log_error(NGX_LOG_EMERG, cycle->log, ngx_errno,
                          "prctl(PR_SET_KEEPCAPS, 1) failed");
            /* fatal */
            exit(2);
        }
//    }
#endif
}
#endif
