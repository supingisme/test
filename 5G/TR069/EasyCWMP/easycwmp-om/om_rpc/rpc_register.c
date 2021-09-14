#include <errno.h>
#include <malloc.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <libubox/uloop.h>
#ifdef JSONC
 #include <json-c/json.h>
#else
 #include <json/json.h>
#endif


#include "external.h"
#include "easycwmp.h"
#include "log.h"

#include "tr069_cwmp_api.h"

struct GetParameterNames_list_node {
    int (*get_response)(GetParameterNames *request, GetParameterNamesResponse *response);
    
    struct list_head list;
};
struct GetParameterValues_list_node {
    int (*get_response)(GetParameterValues *request, GetParameterValuesResponse **response);
    
    struct list_head list;
};




#define RPC_LIST(name) list_##name##_fns
#define RPC_LIST_LOCK(name) list_##name##_fns_rwlock
#define RPC_LIST_LOCK_RDLOCK(name) pthread_rwlock_rdlock(&RPC_LIST_LOCK(name))
#define RPC_LIST_LOCK_WRLOCK(name) pthread_rwlock_wrlock(&RPC_LIST_LOCK(name))
#define RPC_LIST_LOCK_UNLOCK(name) pthread_rwlock_unlock(&RPC_LIST_LOCK(name))
#define DEFINE_RPC_FNs(name) \
    LIST_HEAD(RPC_LIST(name));\
    pthread_rwlock_t RPC_LIST_LOCK(name) = PTHREAD_RWLOCK_INITIALIZER;

    
DEFINE_RPC_FNs(GetParameterNames);
DEFINE_RPC_FNs(GetParameterValues);



int tr069_register_GetParameterNames(int (*get_response)(GetParameterNames *request, GetParameterNamesResponse **response))
{
    struct GetParameterNames_list_node *node = malloc(sizeof(struct GetParameterNames_list_node));
    node->get_response = get_response;

    RPC_LIST_LOCK_WRLOCK(GetParameterNames);
    list_add_tail(&node->list, &RPC_LIST(GetParameterNames));
    RPC_LIST_LOCK_UNLOCK(GetParameterNames);

    return 0;
}

void tr069_register_GetParameterNames_call(GetParameterNames *request)
{
    printf("TR069: GetParameterNames: %s:%d\n", request->ParameterPath, request->NextLevel);
    RPC_LIST_LOCK_RDLOCK(GetParameterNames);
    struct GetParameterNames_list_node *node_iter;
	struct list_head *ilist;
    GetParameterNamesResponse *response = NULL;
	list_for_each(ilist, &RPC_LIST(GetParameterNames)) {
		node_iter = list_entry(ilist, struct GetParameterNames_list_node, list);
        node_iter->get_response(request, &response);
        if( response ) { //查询到结果
            int i = 0;
            for(i=0;i<response->ParameterNum;i++) {
                char *writeable = response->ParameterList[i].Writable==0?"0":"1";
                external_add_list_paramameter(response->ParameterList[i].Name, writeable, NULL, "0");
                printf("TR069: GetParameterNamesResponse: %s:%s\n", response->ParameterList[i].Name, writeable);
            }
            free(response);
        } else { //未查询到结果
            
        }
        response = NULL;
	}
    
    RPC_LIST_LOCK_UNLOCK(GetParameterNames);
}


int tr069_register_GetParameterValues(int (*get_response)(GetParameterValues *request, GetParameterValuesResponse **response))
{
    struct GetParameterValues_list_node *node = malloc(sizeof(struct GetParameterValues_list_node));
    node->get_response = get_response;

    RPC_LIST_LOCK_WRLOCK(GetParameterValues);
    list_add_tail(&node->list, &RPC_LIST(GetParameterValues));
    RPC_LIST_LOCK_UNLOCK(GetParameterValues);

    return 0;
}


void tr069_register_GetParameterValues_call(GetParameterValues *request)
{
    printf("TR069: GetParameterValues: %s\n", request->ParameterNames);
    RPC_LIST_LOCK_RDLOCK(GetParameterValues);
    struct GetParameterValues_list_node *node_iter;
	struct list_head *ilist;
    GetParameterValuesResponse *response = NULL;
	list_for_each(ilist, &RPC_LIST(GetParameterValues)) {
		node_iter = list_entry(ilist, struct GetParameterValues_list_node, list);
        node_iter->get_response(request, &response);
        if( response ) { //查询到结果            
            external_add_list_paramameter(response->Parameter.Name, response->Parameter.Value, NULL, "0");
            printf("TR069: GetParameterNamesResponse: %s:%s\n", response->Parameter.Name, response->Parameter.Value);
            free(response);
        } else { //未查询到结果
            
        }
        response = NULL;
	}
    
    RPC_LIST_LOCK_UNLOCK(GetParameterValues);
}

