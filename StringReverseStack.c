#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    char str[MAX], stack[MAX];
    int top = -1, i, len;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    for (i = 0; i < len; i++) {
        str[i] = stack[top--];
    }

    printf("Reversed string: %s\n", str);
    return 0;
}

