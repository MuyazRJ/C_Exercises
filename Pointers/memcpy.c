#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv) {
    int size = atoi(argv[1]);
    int *array = (int *)malloc(size * sizeof(int));
    int *array2 = (int *)malloc(size * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 101;
    }

    memcpy(array2, array, sizeof(int) * size);

    printf("array1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\narray2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array2[i]);
    }

    free(array); free(array2);
    return 0;
}