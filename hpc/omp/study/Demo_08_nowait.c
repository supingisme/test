#include <stdio.h>
#include <omp.h>

/*
setenv OMP_SCHEDULE "dynamic, 2"; enviroment variable
*/

void main(int argc, char *argv[])
{

        int i, j, id;

        

        omp_set_num_threads(4);

        int count = 0;

        #pragma omp parallel 
        {

                #pragma omp for nowait
                for ( j = 0; j < 8; j ++)
                        printf("before: j = %d, id = %d/%d\n",j,omp_get_thread_num(),omp_get_num_threads());

                #pragma omp for 
                for ( j = 0; j < 8; j ++)
                        printf(" after: j = %d, id = %d/%d\n",j,omp_get_thread_num(),omp_get_num_threads());
                
        }

        





}
