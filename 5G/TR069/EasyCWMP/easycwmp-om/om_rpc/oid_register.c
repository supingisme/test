/**********************************************************************************************************************
** 
** Copyright (c) 2008-2019 ICT/CAS.
** All rights reserved.
**
** File name: oid_register.h
** Description: 
**
** Current Version: 
** $Revision$
** Author: rongtao
** Date: 
**
***********************************************************************************************************************/
    
/* Dependencies ------------------------------------------------------------------------------------------------------*/
#include "vos_common.h"

#include "wrapper.h"
#include "easy_macros.h"
#include "mask.h"
#include "set.h"
#include "shell.h"
#include "proc.h"
#include "rbtree.h"
#include "flog.h"
#include "getpar.h"
#include "netif.h"
#include "file.h"
#include "pair.h"
#include "sm.h"
#include "xml.h"

#include "tr069_cwmp_api.h"


/* Types -------------------------------------------------------------------------------------------------------------*/
enum tr069_oid_node_type {
    tr069_oid_node_type_branch,//枝干
    tr069_oid_node_type_leaf//叶子
};
    
enum tr069_oid_type {
    tr069_oid_type_table,   //snmp中的表
    tr069_oid_type_Scalar,  //snmp中的节点
};



struct tr069_oid_item {
#define TR069_OID_ITEM_SIZE 64
    char oidNameItem[TR069_OID_ITEM_SIZE];
    enum tr069_oid_node_type node_type;
    enum tr069_oid_type oid_type;
    
    /* for RPC Methods */
    tr069_oid_GetParamValue GetParamValue;
    tr069_oid_SetParamValue SetParamValue;
    tr069_oid_GetParamAttribute GetParamAttribute;
    tr069_oid_SetParamAttribute SetParamAttribute;

    /* 保存下一级 */
    volatile int child_init_flag;
    rt_rbtree_t child; //use rt_rbtree_init_nonmalloc 
};



/* Constants ---------------------------------------------------------------------------------------------------------*/


/* Macros ------------------------------------------------------------------------------------------------------------*/




/* Globals -----------------------------------------------------------------------------------------------------------*/
static rt_rbtree_t oid_root = NULL;

/* Functions ---------------------------------------------------------------------------------------------------------*/
static int _unused tr069_oid_tree_node_cmp(void *d1, void *d2)
{
    struct tr069_oid_item *oid1 = d1, *oid2 = d2;
    char *oidName1 = oid1->oidNameItem;
    char *oidName2 = oid2->oidNameItem;

    if(strncmp(oidName1, oidName2, TR069_OID_ITEM_SIZE) > 0) return GT;
    else if(strncmp(oidName1, oidName2, TR069_OID_ITEM_SIZE) == 0) return EQ;
    else if(strncmp(oidName1, oidName2, TR069_OID_ITEM_SIZE) < 0) return LT;

    return EQ;
}

void tr069_oid_tree_create(rt_rbtree_t *tree)
{
    *tree = rt_rbtree_init_nonmalloc("OIDTree", tr069_oid_tree_node_cmp);
}

void tr069_oid_init()
{
    tr069_oid_tree_create(&oid_root);
}

static int _unused __n_item(char ParameterPath[256])
{
    int iItem = 0;
    int iChar = 0;
    int len = strlen(ParameterPath);
    
    while(ParameterPath[iChar] != '\0' && iChar <= len) {
        int i = 0;
        while(ParameterPath[iChar] != '.' && ParameterPath[iChar] != '\0') {
            iChar++;
        }
        iItem++;
        iChar++;
    }
    return iItem;
}

static int _unused __I_item(char ParameterPath[256], int iItem, char oidNameItem[TR069_OID_ITEM_SIZE])
{
    int __iItem = 0;
    int iChar = 0;
    int len = strlen(ParameterPath);
    
    while(ParameterPath[iChar] != '\0' && iChar <= len) {
        memset(oidNameItem, 0, TR069_OID_ITEM_SIZE);
        int i = 0;
        while(ParameterPath[iChar] != '.' && ParameterPath[iChar] != '\0') {
            oidNameItem[i++] = ParameterPath[iChar++];
        }
        oidNameItem[i] = '\0';
        __iItem++;
        iChar++;
        if(__iItem == iItem) {
            return iItem;
        }
    }
    return -1;
}

static struct tr069_oid_item * _unused __oid_tree_add(rt_rbtree_t tree, char ParameterPath[256])
{
//    printf("-------------%s\n", ParameterPath);
    char oidNameItem[TR069_OID_ITEM_SIZE] = {0};
    memset(oidNameItem, 0, TR069_OID_ITEM_SIZE);
    int nItem = __n_item(ParameterPath);
    __I_item(ParameterPath, 1, oidNameItem);
    
    struct tr069_oid_item *new_node = malloc(sizeof(struct tr069_oid_item));
    memset(new_node->oidNameItem, 0, TR069_OID_ITEM_SIZE);
    strcpy(new_node->oidNameItem, oidNameItem);

    int exist_flag = 0;

    rt_rbtree_node_t *node = rt_rbtree_search(tree, new_node);
    if( node ) {
//        printf("Exist >> %s:%s(%d)\n", new_node->oidNameItem, oidNameItem, nItem);
        free(new_node);
        new_node = node->data;
        exist_flag = 1;
    } else {
        tr069_oid_tree_create(&new_node->child);
        int inster_ret = rt_rbtree_insert(tree, new_node, sizeof(struct tr069_oid_item));
//        printf("New   >> %s:%s(%d:%d)\n", new_node->oidNameItem, oidNameItem, nItem, inster_ret);
    }
    
    if(nItem == 1) {
//        printf("Last  >> %s(%d)\n", new_node->oidNameItem, nItem);
        new_node->node_type = tr069_oid_node_type_leaf;
        if(exist_flag) return NULL;
        return new_node;
    } else {
//        printf("Branch>> %s(%d)\n", new_node->oidNameItem, nItem);
        new_node->node_type = tr069_oid_node_type_branch;
                
        int iChar = 0;
        while(ParameterPath[iChar++] != '.');
        return __oid_tree_add(new_node->child, &ParameterPath[iChar]);
    }
    
    
}
int tr069_oid_register(char ParameterPath[256], 
                         tr069_oid_GetParamValue GetParamValue,
                         tr069_oid_SetParamValue SetParamValue,
                         tr069_oid_GetParamAttribute GetParamAttribute,
                         tr069_oid_SetParamAttribute SetParamAttribute)
{
//    printf("-------------------------------%s\n", ParameterPath);
    struct tr069_oid_item *oid = __oid_tree_add(oid_root, ParameterPath);
    if(oid) {
        printf("New Node: %s\n", ParameterPath);
        oid->GetParamValue = GetParamValue;
        oid->SetParamValue = SetParamValue;
        oid->GetParamAttribute = GetParamAttribute;
        oid->SetParamAttribute = SetParamAttribute;
    } else {
        printf("Exist Node: %s\n", ParameterPath);
    }
}




void tr069_oid_display() 
{
    tr069_oid_display_loop(oid_root);
}

void tr069_oid_display_loop(rt_rbtree_t tree)
{
    rt_rbtree_t this_tree = tree;
    struct tr069_oid_item *this_node = NULL;
    rt_rbtree_node_t *find_node = NULL;
    
    for( find_node = rt_rbtree_getfirst(this_tree); find_node != NULL; find_node=rt_rbtree_getnext(find_node)) {
        this_node = find_node->data;
        printf("%s - ", this_node->oidNameItem);
        tr069_oid_display_loop(this_node->child);
    }
    
}
void tr069_oid_destroy()
{
    tr069_oid_destroy_loop(oid_root);
}
void tr069_oid_destroy_loop(rt_rbtree_t tree)
{
    rt_rbtree_t this_tree = tree;
    struct tr069_oid_item *this_node = NULL;
    rt_rbtree_node_t *find_node = NULL;
    
    for( find_node = rt_rbtree_getfirst(this_tree); find_node; find_node=rt_rbtree_getnext(find_node)) {
        this_node = find_node->data;
        tr069_oid_display_loop(this_node->child);
        rt_rbtree_destroy(this_node->child);
        free(this_node);
    }
    
}