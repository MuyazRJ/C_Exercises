#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("One integer argument required.");
        return 1;
    }

    printf("Variable contains %s and is located at 0x%p", argv[1], (void *)&argv[1]);

    return 0;
}