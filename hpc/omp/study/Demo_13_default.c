#include <stdio.h>
#include <omp.h>

void main(int argc, char *argv[])
{

        int i, j, id;

        int sum = 0;

        
        //#pragma omp parallel for default(shared)
        #pragma omp parallel for default(none) shared(sum)
        for ( j = 0; j < 5; j ++) {

                #pragma omp atomic
                sum ++;

                printf("j = %d, id = %d, sum = %d\n",j,omp_get_thread_num(),sum);

        }
        printf("sum = %d\n",sum);


}
