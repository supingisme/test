//int OBJ_new_nid(int num)
//此函数将内部的new_nid 加num，返回原nid。

#include <openssl/objects.h>

int main()
{
    int nid=OBJ_new_nid(100);

    printf("nid = %d\n", nid);
    
    return 0;
}

