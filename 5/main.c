#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


    // 2. Выбираем операцию
    switch (op) {
        case '+':
            add_matrices(a, b, result, n);
            break;
        case '-':
            sub_matrices(a, b, result, n);
            break;
        case '*':
            multiply_matrices(a, b, result, n);
            break;

            return NULL;
    }

    return result;
