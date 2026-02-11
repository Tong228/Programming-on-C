#include <stdio.h>

int main()
{
    double matrix3x3[3][3];
    int matrix2x2[2][2];
     int R[N][N] = {0};
    int n, m, i , j;

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

    //Возведение матрицы в квадрат
    for (n=0; n<3; n++)
    {
        for (m=0; m<3; m++)
        {
            R[i][j] = 0;
            for (int k = 0; k < N; k++) 
            {
                R[i][j] += A[i][k] * A[k][j];
            }
        }
    }

    printf("Press Enter to exits");
    
    // Очистка буфера перед ожиданием, если до этого был ввод
    // fflush(stdin); 
    getchar(); // Я так понимаю 2 гетчар потому что после ввода последнего числа, я нажимаю Enter, что является /n, гетчар его съедает и завершает программу
    getchar(); // А когда их два, то следующий гетчар ждёт уже моего решения закрыть программу

    return 0;
}

