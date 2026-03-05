#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size1;
    int n, m, i , j, k;

    // запись матрицы 
    printf("Enter the size of the square matrix (in one number)");
    scanf("%d",&size1);
    // Выделение памяти под матрицу
    double **matrix1 = (double **)malloc(size1 * sizeof(double *));
    for (int i=0; i < size1; i++)
    {
        matrix1[i] = (double *)malloc(size1 * sizeof(double));
    }

    // Ввод матрицы
    printf("Enter matrix elements\n");
    for (n=0;n<size1;n++)
    {
        for(m=0;m<size1;m++)
        {
            printf("[%d][%d]\n", n, m);
            scanf("%lf", &matrix1[n][m]);
        }
    }

    // Сумма главной диагонали матрицы
    double sum = 0;
    for (n=0; n < size1; n++)
    {
        for (m=0; m  <size1; m++)
        {
            if(m == n) sum += matrix1[n][m];
        }
    }

    printf("Sum of the elements of the main diagonal: %.0lf\n", sum);
    
    // Сумма элементов побочной диагонали
    sum = 0;
    for (n=0; n<size1; n++)
    {
        for (m=0; m<size1; m++)
        {
            if(m == n) sum += matrix1[n][size1 - 1 - m];
        }
    }
    printf("Sum of the elements of the secondary diagonal: %.0lf\n", sum);

    //Является ли матрица Магическим квадратом??

    double sum_diagonal, sum_horizontal, sum_verical = 0;
    //По диагонали
    for (n=0; n < size1; n++)
    {
        for (m=0; m  <size1; m++)
        {
            if(m == n) sum_diagonal += matrix1[n][m];
        }
    }

    //По горизонтали
    for (n=0; n < size1; n++)
    {
        for (m=0; m  <size1; m++)
        {
            if(n == 1) sum_diagonal += matrix1[n][m];
        }
    }

    
}