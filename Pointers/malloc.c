#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char **argv) {
    if (argc == 1) return 1;
    int *array = (int*) malloc((argc - 1) * sizeof(int));

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    qsort(array, argc - 1, sizeof(int), compare);

    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}