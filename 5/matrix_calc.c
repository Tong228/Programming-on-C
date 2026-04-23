#include <stdlib.h>
#include "matrix_calc.h"
// Функция выделения памяти для матрицы
double** allocate_matrix(int n) {
    // Выделяем массив указателей на строки
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        // Для каждой строки выделяем массив элементов
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}
//Функция очистки памяти
void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        //Чистим строку
        free(matrix[i]); 
    }
    //Массив указателей
    free(matrix); 
}

double** calculate_matrix(double** a, double** b, int n, char op) {
    //Выделяем память для результирующего массива
    double** result = allocate_matrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (op == '+') {
                result[i][j] = a[i][j] + b[i][j];
            } 
            else if (op == '-') {
                result[i][j] = a[i][j] - b[i][j];
            } 
            else if (op == '*') {
                result[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    return result;
}