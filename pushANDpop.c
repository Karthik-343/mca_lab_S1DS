#include <stdio.h>
#include <string.h>
#define MAX 100

int main (){
    char stack[MAX];
    int top = -1;           // stack is empty initially
    char sequence[200];     // buffer for user input
	int i;
	char c;
    printf("Enter a sequence of letters and * :\n");
    scanf("%s", sequence);

    printf("\nPopped sequence: ");

    for (i = 0; i < (int)strlen(sequence); i++) {
        c = sequence[i];

        if (c == ' ' || c == '\n') continue;  // ignore spaces and newline

        if (c == '*') {                      // pop operation
            if (top >= 0) {
                printf("%c ", stack[top--]);
            } else {
                printf("\nError: pop on empty stack!\n");
                return 1;
            }
        } else {                             // push operation (letter)
            if (top < MAX - 1) {
                stack[++top] = c;
            } else {
                printf("\nError: stack overflow!\n");
                return 1;
            }
        }
    }

    printf("\n");
    return 0;
}

