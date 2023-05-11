#include <stdio.h> 
#include <stdlib.h> 
#include <mpi.h>
#define ARRAY_SIZE 1000 
int main(int argc, char *argv[]) { 
int rank, size; 
int i, sum = 0; 
int data[ARRAY_SIZE]; 
int local_sum = 0; 
MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
MPI_Comm_size(MPI_COMM_WORLD, &size); 

 
if (rank == 0) 
{ 
printf("Generating random data...\n"); 
for (i = 0; i < ARRAY_SIZE; i++) 
{ 
data[i] = rand() % 100; 
} 
} 
 
MPI_Scatter(data, ARRAY_SIZE/size, MPI_INT, data, ARRAY_SIZE/size, MPI_INT, 0, MPI_COMM_WORLD); 
 
for (i = 0; i < ARRAY_SIZE/size; i++) 
{ 
local_sum += data[i]; 
} 
 
MPI_Reduce(&local_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 
 
if (rank == 0) { 
printf("The sum is: %d\n", sum); 
} 
MPI_Finalize(); 
return 0; 
}
