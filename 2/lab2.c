#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size1, size2;
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

    //Запись матрицы 2 на 2
    printf("Enter the size of the square matrix (in one number)");
    scanf("%d",&size2);

    double **matrix2 = (double **)malloc(size2 * sizeof(double *));
    for (int i=0; i < size2; i++)
    {
        matrix2[i] = (double *)malloc(size2 * sizeof(double));
    }

    printf("Enter matrix elements\n");
    for (n=0;n<size2;n++)
    {
        for(m=0;m<size2;m++)
        {
            printf("[%d][%d]\n", n, m);
            scanf("%lf", &matrix2[n][m]);
        }
    }

    // Выделение памяти для для result_matrix2
    double **result_matrix2 = (double**)malloc(size2 * sizeof(double *));
    for (int i = 0; i < size2; i++)
    {
        result_matrix2[i] = (double *)calloc(size2, sizeof(double *));
    }

    //Возведение матрицы 2 на 2 в квадрат
    for(i = 0; i < size2; i++) 
    {
        for(j = 0; j < size2; j++)
        {
            for(k = 0; k < size2; k++) 
            {
                result_matrix2[i][j] += matrix2[i][k] * matrix2[k][j];
            }
        }
    }

    //Вывод квадрата матрицы 2 на 2 
    printf("Matrix square:\n");
    for(i = 0; i < size2; i++) {
        for(j = 0; j < size2; j++) {
            printf("%.0lf ", result_matrix2[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    // matrix1
    for (int i = 0; i<size1; i++)
    {
        free(matrix1[i]);
    }

    free(matrix1);
    // matrix2
    for (int i = 0; i<size2; i++)
    {
        free(matrix2[i]);
    }

    free(matrix2);
    // result_matrix2
    for (int i = 0; i<size2; i++)
    {
        free(result_matrix2[i]);
    }

    free(result_matrix2);
    printf("Press Enter to exits"); 
    
    // Очистка буфера перед ожиданием, если до этого был ввод
    // fflush(stdin); 
    getchar(); // Я так понимаю 2 гетчар потому что после ввода последнего числа, я нажимаю Enter, что является /n, гетчар его съедает и завершает программу
    getchar(); // А когда их два, то следующий гетчар ждёт уже моего решения закрыть программу
    
    return 0;
}
