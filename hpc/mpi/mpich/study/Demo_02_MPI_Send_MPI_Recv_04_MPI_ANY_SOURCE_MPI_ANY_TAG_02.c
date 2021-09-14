/**
 *  <Parallel programming technology for high performance computing>
 *
 *               @Copyright    Du Zhihui        :edited
 *                             Li Sanli         :review
 *                             Chen Yu Liu Peng :proofreading
 *
 *    Rong Tao study note:    2017.11
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
#include<string.h>
int main(int argc,char *argv[])
{
    int rank, size, i;

    char *msgs = malloc(sizeof(char)*256);
    char *msg  = malloc(sizeof(char)*256);

    MPI_Status status;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    if(rank == 0)
    {
        for(i=1;i<size;i++)
        {
            MPI_Recv(msgs, 256, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            fprintf(stderr,"%s, source = %d, tag = %d\n",msgs, status.MPI_SOURCE, status.MPI_TAG);
        }
    }   
    else
    {
    /**
    -bash-4.1$ mpirun -n 4 ./a argc=1 argv={"rong","tao"}
    */
        msg = argv[rank] ;
        MPI_Send(msg, 256, MPI_CHAR, 0, 10, MPI_COMM_WORLD);
    }


    MPI_Finalize();

}

/*


*/



