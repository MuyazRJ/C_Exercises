#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Require arguments.");
        return -1;
    }

    int array[argc - 1];

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {
        if (array[i] % 2 == 0) {printf("%d is even\n", array[i]);
        } else printf("%d is odd\n", array[i]);
    }

    return 0;
}