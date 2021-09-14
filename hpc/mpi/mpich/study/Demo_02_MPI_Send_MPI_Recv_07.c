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

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int rank, size;

    float *a = malloc(sizeof(float)*10);

    MPI_Status status;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );


    int i;

    if(size != 10)
    {
        if(rank == 0)
        {
            MPI_Abort(MPI_COMM_WORLD,1);
        }
    }
    if(rank == 0)
    {
        for(i=0;i<10;i++){
            a[i] = 1;
        }
        MPI_Send(a, 10, MPI_FLOAT, 5, 0, MPI_COMM_WORLD);
        
    }
    if(rank == 5)
    {
        MPI_Recv(a, 10, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &status);
    }
    for(i=0;i<10;i++)
    {
        printf("rank = %d, a[%d] = %f\n",rank,i,a[i]);
    }

    MPI_Finalize();

}

/*


*/



