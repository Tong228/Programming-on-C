#include <string.h>
#include <stdio.h>

int main(){
    char input[256];
    double total_sum = 0.0;

    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");

    while (token != NULL) {
        printf("Token %s\n", token);
        token = strtok(NULL, " ");
    }

    getchar();
    getchar();

    return 0;
}