/**
 *  <Parallel programming technology for high performance computing>
 *
 *               @Copyright    Du Zhihui        :edited
 *                             Li Sanli         :review
 *                             Chen Yu Liu Peng :proofreading
 *
 *    Rong Tao study note:    2017.10
 *
 */

/**
 * mpicc -o outfile Demo.c 
 * mpirun -n 2 ./outfile > out.txt
 *
 */
/**
   C = A * B      

*/
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int rank, size;

    float *a = malloc(sizeof(float)*10);
    float *c = malloc(sizeof(float)*10);
    float *b = malloc(sizeof(float)*5);

    MPI_Status status;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );


    int i;

    if(size != 3)
    {
        if(rank == 0)
        {
            MPI_Abort(MPI_COMM_WORLD,1);
        }
    }

/**
   C = A * B      

*/


    if(rank == 0)
    {
        for(i=0;i<10;i++)
        {
            a[i] = i;
            if(i<5) b[i] = i;
        }
        for(i=1;i<size;i++)
        {
            MPI_Send(b,5,MPI_FLOAT,i,1,MPI_COMM_WORLD);
            MPI_Send(&a[(i-1)*5],5,MPI_FLOAT,i,2,MPI_COMM_WORLD);
        }
    }
    else
    {
        float *a0 = malloc(sizeof(float)*5);
        float *c0 = malloc(sizeof(float)*5);

        MPI_Recv(b,5,MPI_FLOAT,0,1,MPI_COMM_WORLD,&status);
        MPI_Recv(a0,5,MPI_FLOAT,0,2,MPI_COMM_WORLD,&status);

        for(i=0;i<5;i++)
        {
            c0[i] = a0[i] * b[i];
        }
        MPI_Send(c0,5,MPI_FLOAT,0,3,MPI_COMM_WORLD);
    }
    if(rank == 0)
    {
        for(i=1;i<size;i++)
        {
            MPI_Recv(&c[(i-1)*5],5,MPI_FLOAT,i,3,MPI_COMM_WORLD,&status);
        }
        for(i=0;i<10;i++)
        {
            printf("c[%d] = %f\n",i,c[i]);
        }
    }

    MPI_Finalize();

}

/*


*/



