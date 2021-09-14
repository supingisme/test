#include <malloc.h>
#include <stdio.h>

struct ListNode {
 	int val;     
	struct ListNode *next;
};

#if 0 //生成新的内存
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(!l1) {
		return l2;
	}
	if(!l2) {
		return l1;
	}
	struct ListNode *list = malloc(sizeof(struct ListNode));
	list->next = NULL;
	if(l1) {
		if(l2) {
			if(l1->val <= l2->val) {
				list->val = l1->val;
				list->next = mergeTwoLists(l1->next, l2);
			} else {
				list->val = l2->val;
				list->next = mergeTwoLists(l1, l2->next);
			}
		} else {
			list->val = l1->val;
			list->next = mergeTwoLists(l1->next, NULL);
		}
	} else {
		if(l2) {
			list->val = l2->val;
			list->next = mergeTwoLists(NULL, l2->next);
		}
	}
	return list;
}
#else //使用原有内存节点
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(!l1) {
		return l2;
	}
	if(!l2) {
		return l1;
	}

	if (l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}

}
#endif

struct ListNode i1 = {4,NULL};
struct ListNode i2 = {5,NULL};
struct ListNode i3 = {9,NULL};

struct ListNode jj1 = {1,NULL};
struct ListNode jj2 = {2,NULL};
struct ListNode jj3 = {7,NULL};
struct ListNode jj4 = {10,NULL};

struct ListNode *l1, *l2;

void show_list(struct ListNode *l1)
{
	struct ListNode *list = l1;
	if(l1) {
		while(list) {
			printf("%d ", list->val);
			list = list->next;
		}
		printf("\n");
	}
}

int main() 
{
	l1 = &i1; i1.next = &i2; i2.next = &i3;
	l2 = &jj1; jj1.next = &jj2; jj2.next = &jj3; jj3.next = &jj4;

	show_list(l1);
	show_list(l2);

	struct ListNode* list = NULL;
	list = mergeTwoLists(l1, l2);

	show_list(list);
}
