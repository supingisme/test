#include <stdio.h>
#include <omp.h>

/*
setenv OMP_SCHEDULE "dynamic, 2"; enviroment variable
*/

void main(int argc, char *argv[])
{

        int i, j, id;

        

        omp_set_num_threads(10);

        int count = 0;

        #pragma omp parallel for
        for ( i = 0; i < 25; i ++ ) {

                #pragma omp critical
                count ++ ;
        }
        printf("count = %d\n",count);
        
        #pragma omp parallel for
        for ( i = 0; i < 25; i ++ ) {

                #pragma omp atomic
                count -- ;
        }
        printf("count = %d\n",count);




}
