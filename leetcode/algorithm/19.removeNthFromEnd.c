/*
19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

/*
解题步骤
建立快指针p和慢指针q，记n的初始值为in
快指针p先走，同时变量n自减
当n自减到0时，p已经比慢指针q先走了in步，此后两个指针开始同步移动
当p指向NULL时，遍历结束，循环体不再执行，故此时p刚好比q多走了in+1步，直接删除q的后一结点即可
特殊情况分析：需要删除头节点时，p最多只会比q多走n步，q并未移动，这与删除倒数第n-1个结点的情况是一样的，不过这种情况下n只会自减到0，直接返回头结点的下一个结点即可

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    while(p){
        if(n < 0){ q = q -> next; }       
        n--;
        p = p -> next;
    }
    if(n == 0){ return head -> next; }
    q -> next = q -> next -> next;
    return head;
}

