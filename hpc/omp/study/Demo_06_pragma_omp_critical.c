#include <stdio.h>
#include <omp.h>


int main(){



        int i;
        int sum1 = 0, sum2 = 0;

        #pragma omp parallel for
        for(i=0;i<5;i++)
          {
                #pragma omp critical
                sum1 += i;

                printf("i = %d, sum = %d\n",i,sum1);
          }
        printf("i = %d, sum = %d\n",i,sum1);


        printf("#################################\n");


        #pragma omp parallel for reduction(+:sum2)
        for(i=0;i<5;i++)
          {
                sum2 += i;

                printf("i = %d, sum = %d\n",i,sum2);
          }
        printf("i = %d, sum = %d\n",i,sum2);


























}
