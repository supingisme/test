//24. 两两交换链表中的节点
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//示例:
//
//给定 1->2->3->4, 你应该返回 2->1->4->3.

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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
    
void _swapPairs(struct ListNode**prev_head, struct ListNode* head){
    if(!head) return;

    *prev_head = head->next;

    head->next = head->next->next;

    (*prev_head)->next = head;

}


struct ListNode* swapPairs(struct ListNode* head){
    if(!head)
        return NULL;
    if(!head->next)
        return head;

    _swapPairs(&head, head);

    head->next->next = swapPairs(head->next->next);

    return head;
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

    if(argc == 2) num = atoi(argv[1])?atoi(argv[1]):num;

	struct ListNode *list = creat_list(num);

	show_list(list);

	list = swapPairs(list);

	show_list(list);
}

