#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "triangle.h"

double triangle_perimeter(double a, double b, double c)

{
    return a+b+c;
}

double triangle_area(double a, double b, double c) 

{
    double half_p;
    double s;

    half_p = (a+b+c)/2;
    s = sqrt(half_p*(half_p-a)*(half_p-b)*(half_p-c));
    return s;
}

bool proof_of_correct_triangle(double a, double b, double c)

{
    if (a+b>c) {
    }
    if (c+b>a) {
    }
    if (a+c>b) {
    }
    
}