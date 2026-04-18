#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "matrix_calc.h"

void sum_matrices(double** a, double** b, double** res, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}


void sub_matrices(double** a, double** b, double** res, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}
