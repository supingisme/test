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

    int value;

    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    do{
        if(myid == 0)
        {
            scanf("%d",&value);
            if(numprocs > 1)
            {
                MPI_Send(&value, 1, MPI_INT, myid+1, 0, MPI_COMM_WORLD);
                fprintf(stderr,"%d send (%d) to %d\n",myid, value, myid+1);
            }
        }
        else
        {
            MPI_Recv(&value, 1, MPI_INT, myid-1, 0, MPI_COMM_WORLD, &status);
            fprintf(stderr,"%d receive (%d) to %d\n",myid, value, myid+1);

            if(myid < numprocs-1)
            {
                MPI_Send(&value, 1, MPI_INT, myid+1, 0, MPI_COMM_WORLD);
                fprintf(stderr,"%d send (%d) to %d\n",myid, value, myid+1);
            }
        }
        MPI_Barrier(MPI_COMM_WORLD);

    }while(value >= 0);

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();
}


/*
-bash-4.1$ mpirun -n 10 ./a
5
0 send (5) to 1
1 receive (5) to 2
1 send (5) to 2
2 receive (5) to 3
2 send (5) to 3
3 receive (5) to 4
3 send (5) to 4
4 receive (5) to 5
4 send (5) to 5
5 receive (5) to 6
5 send (5) to 6
6 receive (5) to 7
6 send (5) to 7
7 receive (5) to 8
7 send (5) to 8
8 receive (5) to 9
8 send (5) to 9
9 receive (5) to 10
*/



