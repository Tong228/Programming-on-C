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
    double sum_main_diagonal = 0;
    for (n=0; n < size1; n++)
    {
        for (m=0; m  <size1; m++)
        {
            if(m == n) sum_main_diagonal += matrix1[n][m];
        }
    }

    printf("Sum of the elements of the main diagonal: %.0lf\n", sum_main_diagonal);
    
    // Сумма побочной диагонали
    double sum_secondary_diagonal = 0;
    for (n=0; n<size1; n++)
    {
        for (m=0; m<size1; m++)
        {
            if(m == n) sum_secondary_diagonal += matrix1[n][size1 - 1 - m];
        }
    }
    printf("Sum of the elements of the secondary diagonal: %.0lf\n", sum_secondary_diagonal);

    //Является ли матрица Магическим квадратом??
    double sum_horizontal, sum_verical = 0;
    //Проверяем по диагоналям
    if (sum_main_diagonal == sum_secondary_diagonal)
        //проверяем по вертикалям и горизонталям
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                sum_horizontal += matrix1[i][j];
                sum_verical += matrix1[j][i];
                if (sum_horizontal == sum_verical)
                    printf("It's a magic square!\n");
            }
    }

    for (int i = 0; i<size1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    printf("Press Enter to exits"); 
    
    getchar(); 
    getchar(); 
    return 0;
    
}