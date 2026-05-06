#include <stdio.h>
#include <string.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main() {

    struct humen group1[4];
    struct humen group2[4];
    struct humen temp;

    printf("Enter data for 4 people (name surname year):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%s %s %d", group1[i].name, group1[i].surname, group1[i].year);
        group2[i] = group1[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (group2[j].year > group2[j + 1].year) {
                temp = group2[j];
                group2[j] = group2[j + 1];
                group2[j + 1] = temp;
            }
        }
    }

    getchar();
    getchar();

    return 0;
}