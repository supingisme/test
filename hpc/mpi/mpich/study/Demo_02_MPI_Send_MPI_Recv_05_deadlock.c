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
    int rank, size, i, rebuf[1], sebuf[1];
    MPI_Status status;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    if(size != 2)
    {
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
/** deadlock
    if (rank == 0) 
    {
        MPI_Recv( rebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status );
        MPI_Send( sebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD );
    }
    else 
    {
        MPI_Recv( rebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &status );
        MPI_Send( sebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD );
    }
 */
/** deadlock
    if (rank == 0) 
    {
        MPI_Send( sebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD );
        MPI_Recv( rebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status );
    }
    else 
    {
        MPI_Send( sebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD );
        MPI_Recv( rebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &status );
    }
 */

    if (rank == 0) 
    {
        MPI_Send( sebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD );
        MPI_Recv( rebuf, 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status );
    }
    else 
    {
        MPI_Recv( rebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD, &status );
        MPI_Send( sebuf, 1, MPI_INT, 0, 99, MPI_COMM_WORLD );
    }


    MPI_Finalize();

}

/*


*/



