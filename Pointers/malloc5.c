#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    int *pointer = malloc(new_size);
    memcpy(pointer, ptr, old_size);
    return pointer;
}

int main(int argc, char **argv) {
    /* first malloc space for 5 int */
    int *array = malloc(5 * sizeof(int));
    if(!array) return -1;

    for(int i=0; i<5; i++) {
        array[i] = i*10;
        printf("before realloc, array[%d] = %d\n", i, array[i]);
    }

    /* expand the size to 10 int */
    array = my_realloc(array, 5*sizeof(int), 10*sizeof(int));
    if(!array) return -1;

    for(int i=5; i<10; i++)
        array[i] = i*10;

    for(int i=0; i<10; i++)
        printf("after realloc, array[%d] = %d\n", i, array[i]);

    free(array);
    return 0;
}