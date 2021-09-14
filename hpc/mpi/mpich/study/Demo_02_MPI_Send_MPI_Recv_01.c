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
#include <math.h>

int main(int argc,char *argv[])
{
    int myid, numprocs;
    char message[20];

    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    if(myid == 0)
    {
        strcpy(message, "hello, process I");
        MPI_Send(message, 20, MPI_CHAR, 1, 999, MPI_COMM_WORLD);
    }
    else if(myid == 1)
    {
        MPI_Recv(message, 20, MPI_CHAR, 0, 999, MPI_COMM_WORLD, &status);
        printf("received : %s\n",message);
    }

    MPI_Finalize();
}


/**
MPI_INTEGER 
MPI_REAL 
MPI_DOUBLE_PRECISION 
MPI_COMPLEX 
MPI_LOGICAL 
MPI_CHARACTER 
MPI_BYTE 
MPI_PACKED

 */





