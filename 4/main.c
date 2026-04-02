#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int main() 

{
    double a,b,c,s,p;

    printf("Enter the value of the 3 sides of the triangle: \n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if (proof_of_correct_triangle(a,b,c)) 
    {
        p = triangle_perimeter(a,b,c);
        s = triangle_area(a,b,c);
        printf("Area of triangle: %.2f\n", s);
        printf("Perimeter of triangle: %.2f\n", p);
    }
    else 
    {
       printf("Incorrect triangle"); 
    }

    printf("Press Enter to exits"); 
    
    getchar(); 
    getchar(); 
    return 0;


}

