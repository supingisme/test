
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <malloc.h>
#include <stdio.h>

struct ListNode {
 	int val;     
	struct ListNode *next;
};

struct ListNode* __addTwoNumbers(struct ListNode* l1, struct ListNode* l2, int pre){
	//如果都是空，返回空
	if(l1 == NULL && l2 == NULL && pre != 1) {
		return NULL;
	}
	//有一个不为空，分配内存
	struct ListNode* newnode = malloc(sizeof(struct ListNode));
	int val = ((l1?l1->val:0) + (l2?l2->val:0) + pre);
	int prefix = val>=10?1:0;
	val %= 10;
	newnode->val = val;

	//printf("%d + %d = %d ... %d\n", l1?l1->val:0, l2?l2->val:0, val, prefix);

	newnode->next = __addTwoNumbers(l1?l1->next:NULL, l2?l2->next:NULL, prefix);
	
	return newnode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	return __addTwoNumbers(l1,l2, 0);
}

struct ListNode i1 = {2,NULL};
struct ListNode i2 = {1,NULL};
struct ListNode i3 = {1,NULL};

struct ListNode jj1 = {2,NULL};
struct ListNode jj2 = {3,NULL};
struct ListNode jj3 = {4,NULL};
struct ListNode jj4 = {5,NULL};

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
	list = addTwoNumbers(l1, l2);

	show_list(list);
}
