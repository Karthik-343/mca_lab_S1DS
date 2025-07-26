#include <stdio.h>

void printArray(int a[], int n) 
{
    if (n == 0)
        return;
    printArray(a, n - 1);
    printf("%d ", a[n - 1]);
}

int main() 
{
    int a[10], i, n; 
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    printf("Array elements: ");
    printArray(a, n);
    return 0;
}

