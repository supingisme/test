#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <obstack.h>

#define debug() printf("%s:%d\n",__func__, __LINE__)


void *mymalloc(ssize_t size){
//    debug();
    return malloc(size);
}
void myfree(void*ptr){
//    debug();
    free(ptr);
}



#define obstack_chunk_alloc mymalloc
#define obstack_chunk_free myfree
#define obstack_alloc_failed_handler  TODO


int main()
{
    struct obstack string_obstack;
    obstack_init(&string_obstack);

    printf("obstack_chunk_size = %d\n", obstack_chunk_size(&string_obstack));

    printf("obstack_room = %d\n", obstack_room(&string_obstack));

    char *str3 = (char*) obstack_alloc (&string_obstack, 17);
    printf("obstack_room = %d\n", obstack_room(&string_obstack));
    
    obstack_grow (&string_obstack,str3, 17);
    
    printf("obstack_room = %d\n", obstack_room(&string_obstack));

    obstack_finish(&string_obstack);
    
    obstack_free(&string_obstack, str3);

}





