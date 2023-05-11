#include <stdio.h>
int A[10][10], M[10][10], N[10][10];
int AV[10], Safe[10], Finish[10], R[10][10], nor, nop;
void AcceptData(int X[10][10])
{
    int i, j;
    for (i = 0; i < nop; i++)
    {
        printf("P%d\n", i);
        for (j = 0; j < nor; j++)
        {
            printf("%c:", 65 + j);
            scanf("%d", &X[i][j]);
        }
    }
}
void AcceptAvailable()
{
    int i;
    for (i = 0; i < nor; i++)
    {
        printf("%c:", 65 + i);
        scanf("%d", &AV[i]);
    }
}
void AcceptRequest(int R[10][10])
{
    int i;
    for (i = 0; i < nor; i++)
    {
        printf("%c:", 65 + i);
        scanf("%d", &R[i]);
    }
}
void DisplayData()
{
    int i, j;
    printf("\n\tAllocation\t\tMax\t\tNeed\n");
    printf("\t");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < nor; j++)
        {
            printf("%4c", 65 + j);
        }
        printf("\t");
    }
    for (i = 0; i < nop; i++)
    {
        printf("\nP%d\t", i);
        for (j = 0; j < nor; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\t");

        for (j = 0; j < nor; j++)
        {
            printf("%4d", M[i][j]);
        }
        printf("\t");

        for (j = 0; j < nor; j++)
            printf("%4d", N[i][j]);
    }
    printf("\nAvailable\n");
    for (j = 0; j < nor; j++)
    {
        printf("%4d", AV[j]);
    }
}

void CalcNeed()
{
    int i, j;
    for (i = 0; i < nop; i++)
    {
        for (j = 0; j < nor; j++)
        {
            N[i][j] = M[i][j] - A[i][j];
        }
    }
}
int CheckNeed(int pno)
{
    int i;
    for (i = 0; i < nor; i++)
    {
        if (N[pno][i] > AV[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    printf("\nEnter Number of Process :");
    scanf("%d", &nop);
    printf("\nEnter Number of Resources :");
    scanf("%d", &nor);
    printf("Enter Allocation\n");
    AcceptData(A);
    printf("Enter MAX Requirement\n");
    AcceptData(M);
    printf("Enter Availability\n");
    AcceptAvailable();
    CalcNeed();
    DisplayData();
}