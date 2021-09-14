#include <sys/types.h>
#include <grp.h>

int initgroups(const char *user, gid_t group);


#ifdef __rtoax_study

void __rtoax_study_nginx()
{
    char             *_group;
    struct passwd    *pwd;
    struct group     *grp;

    grp = getgrnam(_group);
    if (grp == NULL) {
        ngx_conf_log_error(NGX_LOG_EMERG, cf, ngx_errno,
                           "getgrnam(\"%s\") failed", _group);
        return NGX_CONF_ERROR;
    }

    ccf->group = grp->gr_gid;

    if (initgroups(ccf->username, ccf->group) == -1) {
        ngx_log_error(NGX_LOG_EMERG, cycle->log, ngx_errno,
                      "initgroups(%s, %d) failed",
                      ccf->username, ccf->group);
    }
}

#endif
