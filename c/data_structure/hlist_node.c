#include <stdio.h>



struct hlist_node {/*   <rongtao 2019.11.13 19:13~24:00>*/
		struct hlist_node *next, **pprev;
};

struct A {
	int id;
	struct hlist_node *hlist;
};

int main()
{
	

	return 0;
}
