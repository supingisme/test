//25. K 个一组翻转链表
//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
// 
//
//示例：
//
//给你这个链表：1->2->3->4->5
//
//当 k = 2 时，应当返回: 2->1->4->3->5
//
//当 k = 3 时，应当返回: 3->2->1->4->5
//
// 
//
//说明：
//
//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

#include <malloc.h>
#include <stdio.h>

struct ListNode {
 	int val;     
	struct ListNode *next;
};

struct ListNode* creat_list(int n){
	if(!n)
	 return NULL;
	int i = 1;
	struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	phead->next  = NULL;
	phead->val = 1;
	if(!phead)
		return NULL;
	struct ListNode *p, *q;
	p = q = phead;
	
	for(i = 1; i < n; ++i){
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->next = q;
		p = q;
		p->val = i + 1;
	}
	return phead;
}



struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *listIter = head;
    struct ListNode *prevNode = NULL;
    struct ListNode beforeHead = {0};

    /* 申请一个大小为K的栈 */
    struct ListNode **listStack = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
    memset(listStack, 0, sizeof(struct ListNode *) * k);

    /* 前面的节点 */
    beforeHead.next = head;
    prevNode = &beforeHead;
    while (listIter != NULL) {
        int cnt = 0;
        /* 循环K次，填充栈 */
        while (cnt < k && listIter != NULL) {
            listStack[cnt] = listIter;
            cnt++;
            listIter = listIter->next;
        }
        /* 不足K个，直接返回 */
        if (cnt != k) {
            break;
        }
        /* K个依次出栈，接入链表 */
        while (cnt > 0) {
            prevNode->next = listStack[cnt - 1];
            prevNode = prevNode->next;
            cnt--;
        }
        prevNode->next = listIter;
    }
    free(listStack);
    return beforeHead.next;
}

void show_list(struct ListNode *list)
{
	struct ListNode *l = list;
	if(l) {
		while(l) {
			printf("%d ", l->val);
			l = l->next;
		}
		printf("\n");
	}
}


int main(int argc, char*argv[]) 
{
    int num = 6;
    int k = 2;

    if( argc < 3 ) {
        printf("Usage: a.out [number of list] [k]\n");
        exit(1);
    }

    num = atoi(argv[1])?atoi(argv[1]):num;
    k = atoi(argv[2])?atoi(argv[2]):k;


	struct ListNode *list = creat_list(num);

	show_list(list);

	list = reverseKGroup(list, k);

	show_list(list);
}


