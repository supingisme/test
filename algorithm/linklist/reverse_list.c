#include <stdio.h>

struct list_node {
    int val;
    struct list_node *next;
};

struct list_node* reverse_list(struct list_node *list)
{
    struct list_node *ret_list = NULL;
    struct list_node *prev = NULL;
    
    while(list) {
        struct list_node *next = list->next;
        list->next = prev;

        prev = list;
        
        if(!next) {
            ret_list = list;
        }
        
        list = next;
    }
    return ret_list;
}


int main()
{
    struct list_node nodes[] = {
        {1, NULL},
        {2, NULL},
        {3, NULL},
        {4, NULL},
        {5, NULL},
    };

    int i;
    for(i=0; i<sizeof(nodes)/sizeof(nodes[0])-1; i++) {
        nodes[i].next = &nodes[i+1];
    }

    struct list_node *list = &nodes[0];

    while(list) {
        printf("%d\n", list->val);
        list = list->next;
    }

    list = &nodes[0];
    list = reverse_list(list);

    
    while(list) {
        printf("%d\n", list->val);
        list = list->next;
    }
    
}
