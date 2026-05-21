#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// Структура person
typedef struct {
    char name[50];
    char surname[50];
    int year;
    char gender[10];
    float height;
} Person;

Person p;

// Функция для сравнения двух людей по выбранным полям
int compare(Person a, Person b, int fields[], int field_count) {
    for (int i = 0; i < field_count; i++) {
        int res = 0;
        int f = fields[i];
        //1 - Year, 2 - Surname, 3 - Gender, 4 - Height
        // Блок сравнения. Если res = 1(а > b) , то поменять местами
        // -1(а < b) оставить как есть
        // 0(a = b) оставить как есть 
        if (f == 1) res = a.year - b.year; // По году
        else if (f == 2) res = strcmp(a.surname, b.surname); // По фамилии. strcmp() - лексикографическое сравнение двух строк
        else if (f == 3) res = strcmp(a.gender, b.gender); // По полу
        else if (f == 4) { // По росту
            if (a.height > b.height) res = 1;
            else if (a.height < b.height) res = -1;
        }

        // Если по текущему полю значения разные, возвращаем результат
        // Если одинаковые, то переходим к следующему полю
        if (res != 0) return res;
    }
    return 0;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    // Создаем файл и записываем в него данные
    FILE *inputFile = fopen("input.txt", "w");
    fprintf(inputFile, "Иванова Оксана 1975 Жен 1.95\n");
    fprintf(inputFile, "Сидоров Николай 1981 Муж 1.81\n");
    fprintf(inputFile, "Магомедов Магомед 2000 Муж 2.00\n");
    fprintf(inputFile, "Баскаков Николай 2003 Муж 2.03\n");
    fprintf(inputFile, "Бенедиктов Камбербетч 1951 Муж 1.51\n");
    fprintf(inputFile, "Драндулетов Драндулет 1915 Муж 1.15\n");
    fprintf(inputFile, "Воробьёва Елена 1956 Жен 1.56\n");
    fprintf(inputFile, "Воробьянинов Ипполит 1978 Муж 1.78\n");
    fprintf(inputFile, "Иванов Иван 1999 Муж 1.99\n");
    fprintf(inputFile, "Петров Алексей 1985 Муж 1.85\n");

    fclose(inputFile);
    printf("File input.txt created\n");

    // Читаем данные из файла в массив
    Person group[50];
    int count = 0;
    FILE *readFile = fopen("input.txt", "r");
    while (fscanf(readFile, "%s %s %d %s %f", 
           group[count].name, group[count].surname, 
           &group[count].year, group[count].gender, 
           &group[count].height) != EOF) {
        count++;
    }
    fclose(readFile);

    // Выбор полей для сортировки
    int sort_fields[4];
    int field_count = 0;
    printf("Select fields to sort by (enter numbers separated by spaces, 0 to end):\n");
    printf("1 - Year, 2 - Surname, 3 - Gender, 4 - Height\n");
    
    for (int i = 0; i < 4; i++) {
        int choice;
        scanf("%d", &choice);
        if (choice == 0) break;
        sort_fields[field_count++] = choice;
    }

    // Сортировка пузырьком
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(group[j], group[j+1], sort_fields, field_count) > 0) {
                Person temp = group[j];
                group[j] = group[j+1];
                group[j+1] = temp;
            }
        }
    }

    // Выводим результат
    printf("\nSorting result:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s | %d | %s | %.2f m\n", 
               group[i].name, group[i].surname, 
               group[i].year, group[i].gender, group[i].height);
    }

    getchar();
    getchar();

    return 0;
}