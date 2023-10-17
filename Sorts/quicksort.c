#include <stdio.h>
#include <stdlib.h>

int partition(int *array, int start, int end) {
    int pivot = array[end - 1];
    int i = start - 1;

    for (int j = start; j < end - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }

    i++;
    int tmp = array[i];
    array[i] = pivot;
    array[end - 1] = tmp;
    return i;
}

void quicksort(int *array, int start, int end) {
    if (start >= end)  return;

    int pivot = partition(array, start, end);
    quicksort(array, start, pivot);
    quicksort(array, pivot + 1, end);
}
 
int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Enter numbers to be sorted.");
        return 1;
    }

    int length = argc - 1;
    int *array = (int *)malloc(sizeof(int) * length);

    for (int i = 0; i < argc - 1; i++) {
        array[i] = atoi(argv[i + 1]);
    }

    quicksort(array, 0, length);

    printf("Size of array: %d\n", length);

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}