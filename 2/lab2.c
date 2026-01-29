#include <stdio.h>

int main()
{
    double matrix3x3[3][3];
    int n, m;

    for (n=0; n<3; n++)
    {
        for (m=0; m<3; m++)
        {
            matrix3x3[n][m] = scanf("%lf", &matrix3x3);
            
        }
    printf("%.0f ", matrix3x3[n][m]);
    printf("\n");
    }
}

