/**
 *  基本二叉树的增删改查
 *
 *  作者：荣涛
 *  时间：2021年8月18日
 */

#include <stdio.h>
#include <malloc.h>

struct tree_node {
    int val;

    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *alloc_node(int val)
{
    struct tree_node *node = malloc(sizeof(struct tree_node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
//    printf("alloc %d\n", val);
    return node;
}

int insert_node(struct tree_node **tree, int val)
{
    if(!(*tree)) {
        *tree = alloc_node(val);
        return 0;
    }
    if((*tree)->val > val) {
        insert_node(&(*tree)->left, val);
    } else if ((*tree)->val < val) {
        insert_node(&(*tree)->right, val);
    } else {
        printf("%d already exist.\n", val);
        return -1;
    }
    return 0;
}

struct tree_node *create_tree(int nodes[], int nr)
{
    if(nr<=0) {
        return NULL;
    }
    struct tree_node *tree = NULL;
    
    int i;
    for(i=0;i<nr;i++) {
        insert_node(&tree, nodes[i]);
    }
    return tree;
}

int for_each_node(struct tree_node *tree, void (*fn)(int val))
{
    if(!fn || !tree){
        return -1;
    }
    for_each_node(tree->left, fn);
    fn(tree->val);
    for_each_node(tree->right, fn);
}

void for_each_cb(int val)
{
    printf("for each %d\n", val);
}

int main()
{
    int arr[] = {4,3,2,5,6,7,8,123,12,3,12,345,234,534,56,4,342,46,3456,354,6};

    struct tree_node *tree = create_tree(arr, sizeof(arr)/sizeof(arr[0]));

    for_each_node(tree, for_each_cb);
}
