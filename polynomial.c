#include <stdio.h>

// Structure to store one term of polynomial
struct Term {
    int coeff;  // coefficient
    int exp;    // exponent
};

int main() {
    int n, i;
    struct Term poly[20];  // array of polynomial terms

    // Input number of terms
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    // Input each term (coefficient and exponent)
    printf("Enter each term (coefficient exponent):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }

    // Display the polynomial
    printf("\nPolynomial is: ");
    for (i = 0; i < n; i++) {
        if (poly[i].coeff == 0) continue; // skip if coefficient is 0

        // Add "+" for positive terms (except the first one)
        if (i > 0 && poly[i].coeff > 0)
            printf(" + ");

        // Display based on exponent
        if (poly[i].exp == 0) {
            printf("%d", poly[i].coeff);            // constant term
        } else if (poly[i].exp == 1) {
            printf("%dx", poly[i].coeff);           // linear term
        } else {
            printf("%dx^%d", poly[i].coeff, poly[i].exp); // higher powers
        }
    }
    printf("\n");

    return 0;
}

