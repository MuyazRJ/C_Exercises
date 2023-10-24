#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt, ##__VA_ARGS__)
#endif

/* Fill the array referenced by ptr with random integers with values between
 * 0 and 99 */
void fill_array(int *ptr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        ptr[i] = rand() % 100;

    DEBUG_PRINT("Generated %d random numbers\n", size);
}

int main(int argc, char **argv) {
    int bins[5] = {0, 0, 0, 0, 0};

    DEBUG_PRINT("Allocating memory\n");
    int *array = malloc(1000 * sizeof(int));
    if (!array) {
        perror("malloc");
        return -1;
    }
    DEBUG_PRINT("Allocation successful\n");

    DEBUG_PRINT("Filling array\n");
    fill_array(array, 1000);

    /* Iterate over the array and according to the value of each element,
     * increment the corresponding bin counter */
    DEBUG_PRINT("Dividing numbers into bins\n");
    for (int i = 0; i < 1000; i++) {
        int n = array[i];

        if (n < 100 / 5)
            bins[0]++;
        else if (n >= 100 / 5 && n < (100 / 5) * 2)
            bins[1]++;
        else if (n >= (100 / 5) * 2 && n < (100 / 5) * 3)
            bins[2]++;
        else if (n >= (100 / 5) * 3 && n < (100 / 5) * 4)
            bins[3]++;
        else
            bins[4]++;
    }

    DEBUG_PRINT("Printing results\n");
    for (int i = 0; i < 5; i++) {
        printf("bin %d: [%03d - %03d[ ", i, (100 / 5) * i, (100 / 5) * (i + 1));
        for (int j = 0; j < (bins[i] * 100) / 1000; j++)
            printf("*");
        printf("\n");
    }

    DEBUG_PRINT("Printing done\n");

    free(array);
    DEBUG_PRINT("Memory freed\n");

    return 0;
}
