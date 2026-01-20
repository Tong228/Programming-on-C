#include <stdio.h>

int main()
{
    double matrix3x3[3][3];
    int n, m, input;

    for (n=0; n<3; n++)
    {
        for (m=0; m<3; m++)
        {
            scanf("%f", &input);
            matrix3x3[n][m] = input;
            printf("%.0f ", matrix3x3[n][m]);
        }
    printf("\n");
    }
}

