#include <stdio.h>
#include <string.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main() {
    // Два массива по 4 элемента
    struct humen group1[4];
    struct humen group2[4];
    struct humen temp;

    // Ввод данных
    printf("Enter data for 4 people (name surname year):\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. ", i + 1);
        scanf("%s %s %d", group1[i].name, group1[i].surname, &group1[i].year);
        
        // Копируем элемент во второй массив
        group2[i] = group1[i];
    }

    // Сортировка пузырьком второго массива по году рождения
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (group2[j].year > group2[j + 1].year) {
                // Меняем элементы местами
                temp = group2[j];
                group2[j] = group2[j + 1];
                group2[j + 1] = temp;
            }
        }
    }

    // Вывод данных
    printf("\nSorted list (by year of birth):\n");
    for (int i = 0; i < 4; i++) {
        printf("%d) %d - %s %s\n", i + 1, group2[i].year, group2[i].name, group2[i].surname);
    }

    getchar();
    getchar();

    return 0;
}