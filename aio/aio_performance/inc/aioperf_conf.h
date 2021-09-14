#ifndef AIOPERF_CONF_H
#define AIOPERF_CONF_H

#define KEYVALLEN       100
#define MAX_FILE_NUM    1000 * 1000

int 
aioperf_conf_get_val(char *profile, char *AppName, char *KeyName, 
    unsigned int *val);
int
aioperf_conf_mgr_init(aioperf_manager_t *mgr, char *conf_file);
int
aioperf_conf_repository_init(aioperf_manager_t *mgr, char *conf_file);

#endif
