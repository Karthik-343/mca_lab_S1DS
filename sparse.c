#include <stdio.h>

int main() {
    int m, n;
    int i,j;
    int sparse[100][3]; // row, column, value
    int k = 0; // count of non-zero elements
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[20][20]; 
    printf("Enter the elements of the matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Sparse representation using 3-tuple form
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix Representation (row  col  value):\n");
    printf("Rows: %d  Cols: %d  Non-zero elements: %d\n", m, n, k);
    printf("Row\tCol\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}

