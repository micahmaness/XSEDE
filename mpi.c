#include <stdio.h>
#include "mpi.h"
#include "globals.h"
#include "nums.h"

int main(argc, argv)
int argc;
char **argv;
{
    double t1, t2;
    
    
    int myID, value, numProcs;
    MPI_Status status;
    
    length = SIZE;
    numProcs = 1;

    MPI_Init(&argc, &argv);
    t1 = MPI_Wtime();
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myID);

    length_per_process = length / numProcs;

    print f"How many digits?";
    scan f("%s", array_size)
    int myarray[array_size];
    
    if (myID == RootProcess)
    {
        if ((fp = fopen(*argv, "r")) == NULL)
        {
            printf("fopen failed on %s\n", filename);
            exit(0);
        }

        fscanf(fp, "%d", &length);

        for (p = 0; p < numProcs - 1; p++)
        {
            for (i = 0; i < length_per_process; i++)
            {
                fscanf(fp, "%d", myArray + i);
            }
            MPI_Send(myArray, length_per_process, MPI_INT, p + 1, tag, MPI_COMM_WORLD);
        }

        for (i = 0; i < length_per_process; i++)
        {
            fscanf(fp, "%d", myArray + i);
        }
    }
    else
    {
        MPI_Recv(myArray, length_per_process, MPI_INT, RootProcess, tag, MPI_COMM_WORLD, &status);
    }

    for (i = 0; i < length_per_process; i++)
    {
        if (myArray[i] == 3)
        {
            myCount++;
        }
    }

    MPI_Reduce(&myCount, &globalCount, 1, MPI_INT, MPI_SUM, RootProcess, MPI_COMM_WORLD);

    if (myID == RootProcess)
    {
        printf("Number of 3's: %d\n", globalCount);
    }
    MPI_Finalize();
    
    t2 = MPI_Wtime();
    printf("Elapsed time: %f\n", t2 - t1);
    return 0;
}