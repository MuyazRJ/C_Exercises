#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        array[i] = i;
        printf("%d\n", array[i]);
    }

    return 0;
}
