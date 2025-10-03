#include <stdio.h>

int main() {
    int m, n;
    int i, j, k1 = 0, k2 = 0, k3 = 0;
    int matrix1[20][20], matrix2[20][20];
    int sparse1[100][3], sparse2[100][3], result[200][3];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Input first matrix
    printf("Enter elements of first matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
            if (matrix1[i][j] != 0) {
                sparse1[k1][0] = i;
                sparse1[k1][1] = j;
                sparse1[k1][2] = matrix1[i][j];
                k1++;
            }
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
            if (matrix2[i][j] != 0) {
                sparse2[k2][0] = i;
                sparse2[k2][1] = j;
                sparse2[k2][2] = matrix2[i][j];
                k2++;
            }
        }
    }

    // Adding sparse matrices (merge process)
    i = j = 0;
    while (i < k1 && j < k2) {
        if (sparse1[i][0] < sparse2[j][0] ||
           (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])) {
            result[k3][0] = sparse1[i][0];
            result[k3][1] = sparse1[i][1];
            result[k3][2] = sparse1[i][2];
            i++;
        } else if (sparse2[j][0] < sparse1[i][0] ||
                  (sparse2[j][0] == sparse1[i][0] && sparse2[j][1] < sparse1[i][1])) {
            result[k3][0] = sparse2[j][0];
            result[k3][1] = sparse2[j][1];
            result[k3][2] = sparse2[j][2];
            j++;
        } else { // Same position ? add values
            result[k3][0] = sparse1[i][0];
            result[k3][1] = sparse1[i][1];
            result[k3][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        k3++;
    }

    // Copy remaining entries
    while (i < k1) {
        result[k3][0] = sparse1[i][0];
        result[k3][1] = sparse1[i][1];
        result[k3][2] = sparse1[i][2];
        i++; k3++;
    }
    while (j < k2) {
        result[k3][0] = sparse2[j][0];
        result[k3][1] = sparse2[j][1];
        result[k3][2] = sparse2[j][2];
        j++; k3++;
    }

    // Print sparse representation
    printf("\nSparse Matrix Representation of First Matrix:\nRow\tCol\tValue\n");
    for (i = 0; i < k1; i++)
        printf("%d\t%d\t%d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);

    printf("\nSparse Matrix Representation of Second Matrix:\nRow\tCol\tValue\n");
    for (i = 0; i < k2; i++)
        printf("%d\t%d\t%d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);

    printf("\nResultant Sparse Matrix after Addition:\nRow\tCol\tValue\n");
    for (i = 0; i < k3; i++)
        if (result[i][2] != 0)   // avoid zero entries after addition
            printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);

    return 0;
}

