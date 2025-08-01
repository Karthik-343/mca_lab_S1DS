#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isOperand(char c) {
    return ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'));
}

void reverseAndSwap(char str[], char rev[]) {
    int i, j = 0;
    char temp;
    // Find length
    for (i = 0; str[i] != '\0'; i++);
    i--; // last char index

    for (; i >= 0; i--) {
        if (str[i] == '(')
            rev[j++] = ')';
        else if (str[i] == ')')
            rev[j++] = '(';
        else
            rev[j++] = str[i];
    }
    rev[j] = '\0';
}

// Convert infix to postfix (used in prefix conversion)
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top != -1 && peek() == '(') {
                pop();
            }
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) > precedence(c)) {
                if (c == '^' && peek() == '^') {
                    break;
                } else {
                    postfix[k++] = pop();
                }
            }
            push(c);
        }
        i++;
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Reverse a string
void reverseString(char str[]) {
    int i, j;
    char temp;
    for (i = 0; str[i] != '\0'; i++);  // find length
    i--;
    for (j = 0; j < i; j++, i--) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

// Custom strlen function
int strLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char infix[MAX], revInfix[MAX], postfix[MAX], prefix[MAX];
	int i;
    printf("Enter infix expression: ");
    gets(infix); // unsafe but for demo only

    reverseAndSwap(infix, revInfix);
    infixToPostfix(revInfix, postfix);

    // Copy postfix to prefix buffer
    int length = strLength(postfix);
    for ( i = 0; i < length; i++) {
        prefix[i] = postfix[i];
    }
    prefix[length] = '\0';

    reverseString(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

