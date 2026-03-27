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

if (proof_of_correct_triangle(a, b, c)) {
        double p = calculate_perimeter(a, b, c);
        double s = calculate_area(a, b, c);
        
        printf("Периметр: %.2f\n", p);
        printf("Площадь: %.2f\n", s);
    } else {
        printf("Треугольник с такими сторонами не существует.\n");
    }

    return 0;
}