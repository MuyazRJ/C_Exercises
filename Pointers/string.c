#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];

    printf("String 1: ");
    fgets(string1, sizeof(string1), stdin);
    printf("String 2: ");
    fgets(string2, sizeof(string1), stdin);
    
    if (strcmp(string1, string2) == 0) {
        printf("strings are similar");
    } else {
        printf("strings are different");
    }

    return 0;
}