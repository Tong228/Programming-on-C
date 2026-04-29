#include <math.h>
#include <stdio.h>
#include "matrix_calc.h"

int main() {
    int n;
    char op;

    printf("Matrix size n: ");
    scanf("%d", &n);

    // Создаем матрицы
    double** A = allocate_matrix(n);
    double** B = allocate_matrix(n);

    printf("Element of matrix A:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%lf", &A[i][j]);

    printf("Element of matrix B:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%lf", &B[i][j]);

    printf("Choose operation (+, -, *): ");
    scanf(" %c", &op);

    // Расчёт
    double** result = calculate_matrix(A, B, n, op);

    // Выводим
    printf("\nResults:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    // Освобождаем память
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(result, n);

    getchar();
    getchar();

    return 0;
}