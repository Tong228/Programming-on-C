#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int main() 

{
    double a,b,c;
    printf("Enter the value of the 3 sides of the triangle: ");
    if (scanf("%lf","%lf","%lf", &a, &b, &c)) != 3 {
        printf("A kak wvesti ne 3 znachenia?");
        return 1;
    }


}