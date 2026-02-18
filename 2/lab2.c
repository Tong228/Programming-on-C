#include <stdio.h>

int main()
{
    double matrix3x3[3][3];
    int matrix2x2[2][2];
    int n, m, i , j, k, result_matrix2x2[2][2];

    // запись матрицы 
    printf("Enter matrix elements\n");
    for (n=0;n<3;n++)
	{
		for(m=0;m<3;m++)
		{
			printf("[%d][%d]\n", n, m);
			scanf("%lf", &matrix3x3[n][m]);
		}
	}
    
    // /*Вывод матрицы*/
    // printf("\n");
    // for (n=0; n<3; n++)
    // {
    //     for (m=0; m<3; m++)
    //     {
    //         printf("%.0lf ", matrix3x3[n][m]);
            
    //     }
    //     printf("\n");
    // }

    //Вывод ээлементов главной диагонали
    double sum = 0;
    for (n=0; n<3; n++)
    {
        for (m=0; m<3; m++)
        {
            if(m == n) sum += matrix3x3[n][m];
        }
    }
    printf("Sum of the elements of the main diagonal: %.0lf\n", sum);

    //Вывод ээлементов побочной диагонали
    sum = 0;
    for (n=0; n<3; n++)
    {
        for (m=0; m<3; m++)
        {
            if(m == n) sum += matrix3x3[n][3 - 1 - m];
        }
    }

    printf("Sum of the elements of the secondary diagonal: %.0lf\n", sum);

    //Запись матрицы 2 на 2
    printf("Enter matrix elements\n");
    for (n=0;n<2;n++)
	{
		for(m=0;m<2;m++)
		{
			printf("[%d][%d]\n", n, m);
			scanf("%lf", &matrix2x2[n][m]);
		}
	}

    //Возведение матрицы 2 на 2 в квадрат
    for(i = 0; i < 2; i++) 
    {
        for(j = 0; j < 2; j++)
        {
            for(k = 0; k < 2; k++) 
            {
                result_matrix2x2[i][j] += matrix2x2[i][k] * matrix2x2[k][j];
            }
        }
    }

    //Вывод квадрата матрицы 2 на 2 
    printf("kvadrat matrix 2 na 2:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%lf ", result_matrix2x2[i][j]);
        }
        printf("\n");
    }

    printf("Press Enter to exits");
    
    // Очистка буфера перед ожиданием, если до этого был ввод
    // fflush(stdin); 
    getchar(); // Я так понимаю 2 гетчар потому что после ввода последнего числа, я нажимаю Enter, что является /n, гетчар его съедает и завершает программу
    getchar(); // А когда их два, то следующий гетчар ждёт уже моего решения закрыть программу

    return 0;
}

