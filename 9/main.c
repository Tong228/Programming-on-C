#include <string.h>
#include <stdio.h>

int main(){
    char A[] = "Hello world\n";
    printf(A);

    char *token = strtok(A, " ");

    while (token != NULL) {
        printf("Token %s\n", token);
        token = strtok(NULL, " ");
    }

    getchar();
    getchar();

    return 0;
}