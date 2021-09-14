//根据oid 以及名称信息生成一个内部的object，示例：
//nid=OBJ_create("1.2.3.44","testSn","testLn")。

#include <openssl/objects.h>

int main()
{
    int nid=OBJ_create("1.2.3.44","testSn","testLn");
    
    return 0;
}


