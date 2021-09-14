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

    float *a = malloc(sizeof(float)*100);

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

    //if(rank == 0)
    //{
        for(i=0;i<100;i++)
        {
            a[i] = 100.0;
        }
       // for (i=1; i<size; i++) 
        //{
       //     MPI_Send(a, 100, MPI_FLOAT, i, 99, MPI_COMM_WORLD);
        //}
    //}
    for(i = 0 + rank; i < 10; i += size)
    {

        float *tmp = malloc(sizeof(float)*12);
        int j;
        for(j = 0; j < 12; j ++)
        {
            if(j == 0 || j == 11)
            {
                tmp[j] = 0.0;
            }
            else 
            {
                tmp[j] = a[j-1 + i*10];
            }
        }
        if(rank == 0)
        {
            MPI_Send(&tmp[10], 1, MPI_FLOAT, rank+1, 0, MPI_COMM_WORLD);
        }
        else if(rank == 9)
        {
            MPI_Send(&tmp[1], 1, MPI_FLOAT, rank-1, 0, MPI_COMM_WORLD);
        }
        else
        {
            MPI_Send(&tmp[10], 1, MPI_FLOAT, rank+1, 0, MPI_COMM_WORLD);
            MPI_Send(&tmp[1], 1, MPI_FLOAT, rank-1, 0, MPI_COMM_WORLD);
        }
        if(rank == 0)
        {
            MPI_Recv(&tmp[11], 1, MPI_FLOAT, rank+1, 0, MPI_COMM_WORLD, &status);
        }
        else if(rank == 9)
        {
            MPI_Recv(&tmp[0], 1, MPI_FLOAT, rank-1, 0, MPI_COMM_WORLD, &status);
        }
        else
        {
            MPI_Recv(&tmp[11], 1, MPI_FLOAT, rank+1, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(&tmp[0], 1, MPI_FLOAT, rank-1, 0, MPI_COMM_WORLD, &status);
        }
        //for(j = 1; j < 11; j ++)
        //{
       //     tmp[j] = ( tmp[j] + tmp[j-1] + tmp[j+1] ) / 3.0;
        //}
        if(rank == 0)printf("---------------------------------\n");
        for(j = 0; j < 12; j ++)
        {
            printf("i = %d, rank = %d, tmp = %f\n",i,rank,tmp[j]);
        }
        
    }



    MPI_Finalize();

}

/*


*/



