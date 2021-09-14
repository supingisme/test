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
    int err = 0;
    double starttime, endtime, tick;


    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    starttime = MPI_Wtime();


    endtime = MPI_Wtime();
    fprintf(stderr,"That tooks %f seconds\n", endtime-starttime);

    tick = MPI_Wtick();
    if (tick > 1.0 || tick < 0.0) 
    {
        err++;
        fprintf( stderr, "MPI_Wtick gave a strange result: (%f)\n", tick );
    }


    MPI_Finalize();
}






