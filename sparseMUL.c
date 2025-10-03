#include <stdio.h>

int main() {
    int m, n, p;
    int i, j, k;
    int A[20][20], B[20][20];
    int sparseA[100][3], sparseB[100][3], result[200][3];
    int k1 = 0, k2 = 0, k3 = 0;

    // Input sizes
    printf("Enter rows and cols of first matrix (m n): ");
    scanf("%d %d", &m, &n);
    printf("Enter cols of second matrix (p): ");
    scanf("%d", &p);

    // Input first matrix
    printf("Enter elements of first matrix (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] != 0) {
                sparseA[k1][0] = i;
                sparseA[k1][1] = j;
                sparseA[k1][2] = A[i][j];
                k1++;
            }
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%d x %d):\n", n, p);
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
            if (B[i][j] != 0) {
                sparseB[k2][0] = i;
                sparseB[k2][1] = j;
                sparseB[k2][2] = B[i][j];
                k2++;
            }
        }
    }

    // Multiply sparse matrices
    for (i = 0; i < k1; i++) {
        for (j = 0; j < k2; j++) {
            if (sparseA[i][1] == sparseB[j][0]) { 
                // Matching column of A with row of B
                int row = sparseA[i][0];
                int col = sparseB[j][1];
                int val = sparseA[i][2] * sparseB[j][2];

                // Check if result already has an entry for (row, col)
                int found = 0;
                for (k = 0; k < k3; k++) {
                    if (result[k][0] == row && result[k][1] == col) {
                        result[k][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k3][0] = row;
                    result[k3][1] = col;
                    result[k3][2] = val;
                    k3++;
                }
            }
        }
    }

    // Print sparse representations
    printf("\nSparse Representation of Matrix A:\nRow\tCol\tVal\n");
    for (i = 0; i < k1; i++)
        printf("%d\t%d\t%d\n", sparseA[i][0], sparseA[i][1], sparseA[i][2]);

    printf("\nSparse Representation of Matrix B:\nRow\tCol\tVal\n");
    for (i = 0; i < k2; i++)
        printf("%d\t%d\t%d\n", sparseB[i][0], sparseB[i][1], sparseB[i][2]);

    printf("\nResultant Sparse Matrix (A x B):\nRow\tCol\tVal\n");
    for (i = 0; i < k3; i++)
        if (result[i][2] != 0)   // ignore zero results
            printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);

    return 0;
}

