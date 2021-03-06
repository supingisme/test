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


void Hello( void )

{
    int nproc, me;
    int type = 1000;
    int buffer[2], node;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &me);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    if (me == 0) 
    {
        printf("\nHello test from all to all\n");
        fflush(stdout);
    }
    for (node = 0; node<nproc; node++) 
    {
        if (node != me) 
        {
            buffer[0] = me; 
            buffer[1] = node; 
            MPI_Send(buffer, 2, MPI_INT, node, type, MPI_COMM_WORLD);

            MPI_Recv(buffer, 2, MPI_INT, node, type, MPI_COMM_WORLD, &status);

            if ( (buffer[0] != node) || (buffer[1] != me) ) 
            {

                (void) fprintf(stderr, "Hello: %d!=%d or %d!=%d\n", buffer[0], node, buffer[1], me);
                printf("Mismatch on hello process ids; node = %d\n", node);
            }
            printf("Hello from %d to %d\n", me, node);

            fflush(stdout);
        }
    }
}

int main(int argc,char *argv[])
{
    int me, option, namelen, size;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&me);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (size < 2) 
    {
        fprintf(stderr, "systest requires at least 2 processes" );
        MPI_Abort(MPI_COMM_WORLD,1);
    }
    MPI_Get_processor_name(processor_name,&namelen);

    fprintf(stderr,"Process %d is alive on %s\n", me, processor_name);
    MPI_Barrier(MPI_COMM_WORLD);

    Hello();

    MPI_Finalize();
}

/*
-bash-4.1$ mpicc -o a Demo.c
-bash-4.1$ mpirun -n 3 ./a
Process 0 is alive on AMAX
Process 1 is alive on AMAX
Process 2 is alive on AMAX

Hello test from all to all
Hello from 0 to 1
Hello from 0 to 2
Hello from 1 to 0
Hello from 1 to 2
Hello from 2 to 0
Hello from 2 to 1

*/



