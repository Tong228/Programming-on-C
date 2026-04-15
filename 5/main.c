#include <stdio.h>
#include <stdlib.h>

int main() 
{
    double **matrix1 = (double **)malloc(size1 * sizeof(double *));
    for (int i=0; i < size1; i++)
    {
        matrix1[i] = (double *)malloc(size1 * sizeof(double));
    }
}