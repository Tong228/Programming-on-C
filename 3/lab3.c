#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int size1;
    int n, m, i , j, k;
    char buffer[81];
    printf("Enter 80 symbols: ");
    fgets(buffer, 80 , stdin);

    printf("Text before conversion: %s\n", buffer);
    printf("String length: %lu\n", strlen(buffer));

    for (i = 0; buffer[i] != 0; i++)
    {
        if (buffer[i]=='a')
        {
            buffer[i] = 'A';
        }
        else if (buffer[i]=='b')
        {
            buffer[i] = 'B';
        }
    }

    printf("Text after conversion: %s\n", buffer);
    printf("String length: %lu\n", strlen(buffer));

    //81 Потому что в конце любой строки в C обязан стоять невидимый «нулевой символ» '\0' означающий что это string

    // запись матрицы 
    printf("Enter the size of the square matrix (in one number): ");
    scanf("%d", &size1);
    // if (scanf("%d", &size1) != 1 || size1 <= 0);
    //     printf("Invalid size!\n");
    //     return 1;
    

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
    double sum_horizontal = 0;
    double sum_vertical = 0;
    //Проверяем по диагоналям   
    if (sum_main_diagonal == sum_secondary_diagonal)
        //проверяем по вертикалям и горизонталям
        for (i = 0; i < size1; i++) 
        {
            for (j = 0; j < size1; j++) 
            {
                sum_horizontal += matrix1[i][j];
                sum_vertical += matrix1[j][i];
            }

            if (sum_main_diagonal == sum_horizontal && sum_main_diagonal == sum_vertical)
                printf("It's a magic square!\n");
                break;

    }
    for (i = 0; i<size1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    printf("Press Enter to exits"); 
    
    getchar(); 
    getchar(); 
    return 0;
    
}