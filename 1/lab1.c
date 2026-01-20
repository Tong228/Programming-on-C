#include <stdio.h>
#include <math.h>

int main() 
{
    double a = 1, b = -2, c = 1;
    double d;
    double x1, x2;

    d = pow(b, 2) - 4 * a * c;
    /*printf("%f", d);*/

    if(d>0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %f\nx2 = %f", x1, x2);
    }

    if(d==0)
    {
        x1 = -b / (2 * a);
        printf("%f", x1);
    }
    
    if(d<0)
    {
        printf("Уравнение не имеет корней");
        return 0;
    }
}