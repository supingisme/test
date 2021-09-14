#include <stdio.h>

struct a{
    int id;
};
struct b {
    struct a a;
};
#define B2A_ID(pa) (((struct b*)pa)->a.id)

void func(int *id){*id=123;}

int main()
{
    struct b b;
    func(&B2A_ID(&b));
    printf("di = %d\n", b.a.id);

    return 0;
}

