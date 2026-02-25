#include <stdio.h>
#include <stdlib.h>

int main()
{
    // === МАТРИЦА 1 (double) ===
    int size1;
    printf("Введите размер первой матрицы (NxN): ");
    scanf("%d", &size1);
    
    // Выделение памяти для матрицы 1
    double **matrix1 = (double **)malloc(size1 * sizeof(double *));
    for (int i = 0; i < size1; i++)
    {
        matrix1[i] = (double *)malloc(size1 * sizeof(double));
    }
    
    // Ввод матрицы 1
    printf("\nВведите элементы матрицы %dx%d:\n", size1, size1);
    for (int n = 0; n < size1; n++)
    {
        for (int m = 0; m < size1; m++)
        {
            printf("[%d][%d]: ", n, m);
            scanf("%lf", &matrix1[n][m]);
        }
    }
    
    // Вывод матрицы 1
    printf("\nВаша матрица %dx%d:\n", size1, size1);
    for (int n = 0; n < size1; n++)
    {
        for (int m = 0; m < size1; m++)
        {
            printf("%.2lf ", matrix1[n][m]);
        }
        printf("\n");
    }
    
    // Сумма главной диагонали
    double sum = 0;
    for (int n = 0; n < size1; n++)
    {
        sum += matrix1[n][n];
    }
    printf("\nСумма элементов главной диагонали: %.2lf\n", sum);
    
    // Сумма побочной диагонали
    sum = 0;
    for (int n = 0; n < size1; n++)
    {
        sum += matrix1[n][size1 - 1 - n];
    }
    printf("Сумма элементов побочной диагонали: %.2lf\n", sum);
    
    // === МАТРИЦА 2 (int) ===
    int size2;
    printf("\nВведите размер второй матрицы (NxN): ");
    scanf("%d", &size2);
    
    // Выделение памяти для матрицы 2
    int **matrix2 = (int **)malloc(size2 * sizeof(int *));
    for (int i = 0; i < size2; i++)
    {
        matrix2[i] = (int *)malloc(size2 * sizeof(int));
    }
    
    // Выделение памяти для результата
    int **result_matrix = (int **)malloc(size2 * sizeof(int *));
    for (int i = 0; i < size2; i++)
    {
        result_matrix[i] = (int *)malloc(size2 * sizeof(int));
    }
    
    // Ввод матрицы 2
    printf("\nВведите элементы матрицы %dx%d:\n", size2, size2);
    for (int n = 0; n < size2; n++)
    {
        for (int m = 0; m < size2; m++)
        {
            printf("[%d][%d]: ", n, m);
            scanf("%d", &matrix2[n][m]);
        }
    }
    
    // Вывод матрицы 2
    printf("\nВаша матрица %dx%d:\n", size2, size2);
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Инициализация result_matrix нулями
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            result_matrix[i][j] = 0;
        }
    }
    
    // Возведение матрицы в квадрат
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            for (int k = 0; k < size2; k++)
            {
                result_matrix[i][j] += matrix2[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Вывод квадрата матрицы
    printf("\nКвадрат матрицы %dx%d:\n", size2, size2);
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }
    
    // === ОСВОБОЖДЕНИЕ ПАМЯТИ ===
    
    // Освобождение matrix1
    for (int i = 0; i < size1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);
    
    // Освобождение matrix2
    for (int i = 0; i < size2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);
    
    // Освобождение result_matrix
    for (int i = 0; i < size2; i++)
    {
        free(result_matrix[i]);
    }
    free(result_matrix);
    
    printf("\nНажмите Enter для выхода...");
    getchar();
    getchar();
    
    return 0;
}