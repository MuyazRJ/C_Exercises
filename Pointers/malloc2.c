#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Enter the dimensions of a 2d array (m x n).\n");
        return 1;
    }

    int m = atoi(argv[1]), n = atoi(argv[2]);
    int **arr = (int **)malloc(m * sizeof(int *));  
    
    for (int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (int r = 0; r < m; r++) {
        if (r > 0) printf("\n");
        for (int c = 0; c < n; c++) {
            arr[r][c] = r * n + c;
            printf("%d ", arr[r][c]);
        }
    }

    free(arr);

    return 0;
}