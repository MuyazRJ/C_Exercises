#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[100];

    printf("Enter String: ");
    fgets(string, sizeof(string), stdin);

    char *token = strtok(string, " ");

    while (token != NULL) {
        token[0] = toupper(token[0]);
        printf("%s ", token);
        token = strtok(NULL, " "); // Get the next word
    }

    return 0;
}