/*************************************************************
 * file:reverse_twins_node_of_list.c
 * brief:交换单链表中相邻的两个点
 * yejing@2015.1.20    1.0      creat
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
 
typedef struct _node_t{
	struct _node_t *next;
	int value;
}node_t;
 
node_t* creat_list(int n){
	if(!n)
	 return NULL;
	int i = 1;
	node_t* phead = (node_t*)malloc(sizeof(node_t));
	phead->next  = NULL;
	phead->value = 1;
	if(!phead)
		return NULL;
	node_t *p, *q;
	p = q = phead;
	
	for(i = 1; i < n; ++i){
		q = (node_t*)malloc(sizeof(node_t));
		p->next = q;
		p = q;
		p->value = i + 1;
	}
	return phead;
}
 
node_t* reverse_twins_node_of_list(node_t* phead){
	if(!phead)
		return NULL;
	if(!phead->next)
		return phead;
	int i = 2;
	node_t* n = phead;
	phead = phead->next->next;
	while(i){
		node_t* m = n;
		n = n->next;
		m->next = phead;
		phead = m;
		--i;
	}
	phead->next->next = reverse_twins_node_of_list(phead->next->next);
	return phead;
}
 
void show_list(node_t* phead, int before_after){
	if(!phead)
		return;
		
	node_t* tmp = phead;
	if(before_after)
		printf("before transfer ");
	else
		printf("after  transfer ");
	printf("list is:");	
	while(tmp){
		printf(" %d", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	return;
}
 
int main(int argc, char* argv[]){
	int count;
	printf("input list node count:\n");
	scanf("%d", &count);
	getchar();
	node_t* phead = creat_list(count);
	show_list(phead, 1);
	phead = reverse_twins_node_of_list(phead);
	show_list(phead, 0);
	
	return 1;
}

