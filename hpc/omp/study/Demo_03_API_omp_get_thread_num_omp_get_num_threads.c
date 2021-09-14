#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void t(){

        int i, j;

        #pragma omp parallel for
        for ( i = 0; i < 4; i++ ) {

                printf("t(): i = %d, id = %d/%d\n", i, omp_get_thread_num(), omp_get_num_threads());

                //#pragma omp parallel for
                for ( j = 0; j < 2; j ++ ) {

                        printf("i = %d, j = %d\n",i,j);
                    }
          }

}

int main()
{

        int i, id, nd;

        #pragma omp parallel for
        for(i=0; i<10;i++){

                id = omp_get_thread_num();
                nd = omp_get_num_threads();
                printf("i = %d, id = %d/%d\n",i,id,nd);
          }

        printf("#################################################################\n");

        t();































}//main
