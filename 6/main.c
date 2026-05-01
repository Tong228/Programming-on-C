#include <stdio.h>
#include <locale.h>

int main() {
   
    inputFile = fopen("Names.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    // Открываем (или создаем) файл для записи
    outputFile = fopen("Names1.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    

    return 0;
}