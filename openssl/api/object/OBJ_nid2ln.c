//const char *OBJ_nid2ln(int n)
//////根据nide 得到对象的描诉。

#include <openssl/objects.h>

int main()
{
    int nid=OBJ_new_nid(100);

    printf("nid = %d, %s\n", nid, OBJ_nid2ln(nid));
    
    return 0;
}

