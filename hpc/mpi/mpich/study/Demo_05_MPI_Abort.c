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


    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    fprintf(stderr,"myid = %d\n",myid);
    if(myid == 3)
    {
        MPI_Abort(MPI_COMM_WORLD, 99);
    }    
    fprintf(stderr,"myid = %d\n",myid);

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();
}






