#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    int array[argc - 1];

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    int length = sizeof(array) / sizeof(array[0]);
    qsort(array, length, sizeof(int), compare);

    for (int i = 0; i < length; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}