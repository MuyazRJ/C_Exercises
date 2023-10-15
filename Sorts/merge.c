#include <stdio.h>
#include <stdlib.h>

int *mergesort();
int *merge();

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Provide numbers to be sorted.");
        return -1;
    }

    int length = argc - 1;
    int *array = (int *)malloc(sizeof(int) * length);
    
    for (int i = 0; i < argc - 1; i++) {
        array[i] = atoi(argv[i + 1]);
    }

    array = mergesort(array, length);

    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}

int *mergesort(int *arr, int length) {
    if (length < 2) return arr;

    const int m = length / 2;
    int *arr1 = (int *)malloc(sizeof(int) * m);
    int *arr2 = (int *)malloc(sizeof(int) * (length - m));

    for (int i = 0; i < length; i++) {
        if (i < m) arr1[i] = arr[i];
        else arr2[i - m] = arr[i];
    }

    arr1 = mergesort(arr1, m);
    arr2 = mergesort(arr2, length - m);
    free(arr);
    
    int *merged = merge(arr1, arr2, m, (length - m));

    free(arr1);
    free(arr2);
    return merged;
}

int *merge(int *arr1, int *arr2, int leftLength, int rightLength) {
    int *merged = (int *)malloc(sizeof(int) * (leftLength + rightLength));
    int l = 0, r = 0, i = 0;

    while (l < leftLength && r < rightLength) {
        if (arr1[l] < arr2[r]) {
            merged[i] = arr1[l];
            l++;
        } else {
            merged[i] = arr2[r];
            r++;
        }

        i++;
    }

    for (l; l < leftLength; l++) {
        merged[i] = arr1[l];
        i++;
    }

    for (r; r < rightLength; r++) {
        merged[i] = arr2[r];
        i++;
    }

    return merged;
}