#include <stdio.h>
#include <stdlib.h>

//Структура для 
typedef struct {
    char lastname[50];
    char firstname[50];
    char patronymic[50];
    int year;
} Person;

Person p;

int main() {
    // Создаём текстовый файл
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        perror("File creation error");
        return 1;
    }

    // Заполняем файл
    fprintf(inputFile, "Иванов Петр Сергеевич 1975\n");
    fprintf(inputFile, "Сидоров Николай Андреевич 1981\n");
    fprintf(inputFile, "Магомедов Магомед Магомедович 2000\n");
    fprintf(inputFile, "Баскаков Николай Ларионович 2003\n");
    fprintf(inputFile, "Бенедиктов Камбербетч Васильевич 1951\n");
    fprintf(inputFile, "Драндулетов Драндулет Епатьевич 1915\n");
    fprintf(inputFile, "Воробьёв Андрей Викторович 1956\n");
    fprintf(inputFile, "Воробьянинов Ипполит Матвеевич 1978\n");
    fprintf(inputFile, "Иванов Иван Иванович 1999\n");
    fprintf(inputFile, "Петров Алексей Игоревич 1985\n");

    fclose(inputFile);
    printf("File input.txt created\n");

    //Читаем данные из names.txt , фильтруем и записываем в output.txt
    FILE *src = fopen("input.txt", "r");
    FILE *dest = fopen("output.txt", "w");

    if (src == NULL || dest == NULL) {
        perror("Error while filtering");
        return 1;
    }

    // Считываем данные пока не дойдем до конца файла(EOF). %s - строка до пробела. %d - число
    while (fscanf(src, "%s %s %s %d", p.lastname, p.firstname, p.patronymic, &p.year) != EOF) {
        if (p.year > 1980) {
            fprintf(dest, "%s %s %s %d\n", p.lastname, p.firstname, p.patronymic, p.year);
        }
    }

    fclose(src);
    fclose(dest);

    printf("Well done\n");

    getchar();
    getchar();

    return 0;
}