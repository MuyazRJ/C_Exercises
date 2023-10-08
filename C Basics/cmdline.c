#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Enter 3 numbers\n");
        return 1;
    }

    double product = 1;

    for (int i = 1; i < argc; i++) {
        product *= strtod(argv[i], NULL);
    }

    printf("%lf", product);

    return 0;
}

