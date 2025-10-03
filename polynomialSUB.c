#include <stdio.h>

// Arrays to store coefficients of polynomials
int a1[10], a2[10], diff[10];
int n1, n2;

// Function to read coefficients of a polynomial
void read(int a[], int n) {
    int i;
    printf("Enter the coefficients\n");
    for (i = n; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }
}

// Function to display a polynomial
void disp(int a[], int n) {
    int i;
    for (i = n; i >= 0; i--) {
        if (a[i] != 0) {  // skip if coefficient is 0

            // Put '+' for positive terms (not at the beginning)
            if ((i != n) && (a[i] > 0)) {
                printf("+");
            }

            // Display coefficient and variable
            if (i > 1) {
                printf("%dx^%d ", a[i], i);   // higher powers
            } else if (i == 1) {
                printf("%dx ", a[i]);         // linear term
            } else {
                printf("%d ", a[i]);          // constant
            }
        }
    }
}

// Function to subtract two polynomials
// result = a1 - a2
void subtract(int a1[], int a2[], int diff[], int n1, int n2) {
    int maxdeg = (n1 > n2) ? n1 : n2;
    int i;

    // Initialize result array to 0
    for (i = 0; i <= maxdeg; i++) {
        diff[i] = 0;
    }

    // Copy polynomial 1 into result
    for (i = 0; i <= n1; i++) {
        diff[i] += a1[i];
    }

    // Subtract polynomial 2
    for (i = 0; i <= n2; i++) {
        diff[i] -= a2[i];
    }
}

int main() {
    int maxdeg;

    // Input degrees of two polynomials
    printf("Enter degree of polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter degree of polynomial 2: ");
    scanf("%d", &n2);

    // Highest degree among the two
    maxdeg = (n1 > n2) ? n1 : n2;

    // Read both polynomials
    read(a1, n1);
    printf("\n");
    read(a2, n2);
    printf("\n");

    // Subtract polynomials
    subtract(a1, a2, diff, n1, n2);

    // Display results
    printf("\nPolynomial 1: \t");
    disp(a1, n1);
    printf("\nPolynomial 2: \t");
    disp(a2, n2);
    printf("\nDifference (P1 - P2): \t");
    disp(diff, maxdeg);

    return 0;
}

