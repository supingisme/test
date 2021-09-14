#include <stdio.h>
#include <omp.h>

/*
setenv OMP_SCHEDULE "dynamic, 2"; enviroment variable
*/

void main(int argc, char *argv[])
{

        int i, j, id;

        

        omp_set_num_threads(4);

        int a[5];

        #pragma omp parallel 
        {

                #pragma omp for
                for ( j = 0; j < 5; j ++)
                        a[j] = j * j;

                #pragma omp master
                for ( j = 0; j < 5; j ++)
                        printf(" a[%d] = %d, j = %d, id = %d/%d\n",j,a[j],j,omp_get_thread_num(),omp_get_num_threads());
                
        }

        





}
