#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    clock_t start_time, end_time;
    double sleep_duration;

    start_time = clock();
    printf("Sleeping for %d seconds...\n", n);
    sleep(n);
    end_time = clock();

    // Calculate the sleep duration in seconds
    sleep_duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sleep duration: %.6f seconds\n", sleep_duration);

    return 0;
}
