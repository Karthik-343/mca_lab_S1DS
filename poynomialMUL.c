#include <stdio.h>

// Arrays to store coefficients of polynomials
int a1[10], a2[10], prod[20];  // prod size must be larger (sum of degrees)
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

// Function to multiply two polynomials
// result = a1 * a2
void multiply(int a1[], int a2[], int prod[], int n1, int n2) {
    int i, j;
    int deg = n1 + n2;  // degree of result

    // Initialize product array to 0
    for (i = 0; i <= deg; i++) {
        prod[i] = 0;
    }

    // Multiply coefficients
    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++) {
            prod[i + j] += a1[i] * a2[j];
        }
    }
}

int main() {
    int deg;

    // Input degrees of two polynomials
    printf("Enter degree of polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter degree of polynomial 2: ");
    scanf("%d", &n2);

    // Read both polynomials
    read(a1, n1);
    printf("\n");
    read(a2, n2);
    printf("\n");

    // Multiply polynomials
    multiply(a1, a2, prod, n1, n2);

    deg = n1 + n2;  // max degree of result

    // Display results
    printf("\nPolynomial 1: \t");
    disp(a1, n1);
    printf("\nPolynomial 2: \t");
    disp(a2, n2);
    printf("\nProduct: \t");
    disp(prod, deg);

    return 0;
}

