#include <string.h>

#include "execute.h"
#include "log.h"


LIST_HEAD(execution_ready_list);


void load_execution_ready_list_from_xml(xmlXPathContextPtr cfgctx)
{
    char *path = NULL, *name = NULL, *args = NULL;
    struct execution *exe = NULL;
    int index = 0;
    
    while(1) {
        path = (char*)get_xml_node_value_next(cfgctx, (xmlChar*)"/config-root/executions/exe", index);
        name = (char*)get_xml_node_prop_value_next(cfgctx, (xmlChar*)"/config-root/executions/exe", (xmlChar*)"name", index);
        args = (char*)get_xml_node_prop_value_next(cfgctx, (xmlChar*)"/config-root/executions/exe", (xmlChar*)"args", index);
        
        if(!path || !name || strlen(name) <= 0 || strlen(path) <= 0) {
            break;
        }
        debug("%s/%s %s\n", path, name, args);
        
        exe = malloc(sizeof(struct execution));

        exe->exeid = (long int)exe;

        exe->path = strdup(path);
        exe->name = strdup(name);
        exe->args = strdup(args);

        list_add_tail(&exe->list, &execution_ready_list);

        index++;
    }
}
