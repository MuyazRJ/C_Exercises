#include <stdio.h>

int main() {
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(unsigned long long));
    printf("%lu\n", (sizeof(int) * sizeof(double) * sizeof(unsigned long long)));
    
    return 0;
}