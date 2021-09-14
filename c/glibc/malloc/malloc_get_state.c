#include <malloc.h>

int main()
{
    char *p1 = malloc(1039);
    
    char *state = malloc_get_state();
    if(state){
        printf("state %p\n", state);
    }

    int ret = malloc_set_state(state);
    printf("ret %d\n", ret);
    
    free(p1);
}

