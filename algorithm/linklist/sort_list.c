#include <stdio.h>

struct list_node {
    int val;
    struct list_node *next;
};


void swap_node(struct list_node *node1, struct list_node *node2)
{
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;

}

struct list_node* sort_list(struct list_node *list)
{

    struct list_node *ret_list = list;
    
    while(list) {

        struct list_node *list2 = list->next;
        
        while(list2) {
            if(list2->val > list->val) {
//                printf("swap: %d <-> %d\n", list2->val, list->val);
                swap_node(list, list2);
            }
            list2 = list2->next;
        }
        list = list->next;
    }
    return ret_list;
}


int main()
{
    struct list_node nodes[] = {
        {8, NULL},
        {2, NULL},
        {7, NULL},
        {4, NULL},
        {5, NULL},
        {4, NULL},
        {5, NULL},
        {9, NULL},
        {90, NULL},
        {4, NULL},
        {10, NULL},
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
    list = sort_list(list);

    printf("Sort List\n");
    
    while(list) {
        printf("%d\n", list->val);
        list = list->next;
    }
    
}

