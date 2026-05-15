#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Структура person
typedef struct {
    char name[50];
    char surname[50];
    int year;
    char gender[10];
    float height;
} Person;

// Функция для сравнения двух людей по выбранным полям
int compare(Person a, Person b, int fields[], int field_count) {
    for (int i = 0; i < field_count; i++) {
        int res = 0;
        int f = fields[i];

        if (f == 1) res = a.year - b.year; // По году
        else if (f == 2) res = strcmp(a.surname, b.surname); // По фамилии
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
    // Создаем файл и записываем в него данные
    FILE *f_out = fopen("people.txt", "w");
    fprintf(f_out, "Ivan Ivanov 1995 male 1.82\n");
    fprintf(f_out, "Sophia Petrova 2000 female 1.65\n");
    fprintf(f_out, "Petr Ivanov 1995 male 1.75\n");
    fprintf(f_out, "Elena Pavlovna 1990 female 1.70\n");
    fclose(f_out);

    // Читаем данные из файла в массив
    Person group[100];
    int count = 0;
    FILE *f_in = fopen("people.txt", "r");
    while (fscanf(f_in, "%s %s %d %s %f", 
           group[count].name, group[count].surname, 
           &group[count].year, group[count].gender, 
           &group[count].height) != EOF) {
        count++;
    }
    fclose(f_in);

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
        printf("%s %s | %d | %s | %.2f м\n", 
               group[i].name, group[i].surname, 
               group[i].year, group[i].gender, group[i].height);
    }

    return 0;
}