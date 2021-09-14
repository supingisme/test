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
 * mpirun -n 10 ./outfile > out.txt
 *
 */


#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int myid, numprocs;
    int namelen;
    int version, subversion, ierr;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    MPI_Get_processor_name(processor_name,&namelen);
    MPI_Get_version(&version, &subversion);


    fprintf(stdout,"stdout Process %d of %d on %s\n",myid, numprocs, processor_name);//mpirun -n 10 ./a > out.txt
    fprintf(stderr,"stderr Process %d of %d on %s\n",myid, numprocs, processor_name);//screen
    fprintf(stderr,"version %d.%d \n",version, subversion);//screen
    perror("rong");//screen

    MPI_Finalize();
}
