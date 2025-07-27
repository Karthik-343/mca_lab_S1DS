#include <stdio.h>

int stack[5], top = -1;

void push(int e) {
    if (top == 4) {
        printf("Stack is full\n");
    } else {
        stack[++top] = e;
        printf("\nPushed %d\n", e);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("\nPopped %d\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("\nTop Element is %d\n", stack[top]);
    }
}
 
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Current Stack: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int menu() {
    int ch;
    printf("\n1 - Push\n2 - Pop\n3 - Peek\n4 - Display\n5 - Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processStack() {
    int ch, val;
    for (ch = menu(); ch != 5; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
            	display();
            	break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
}

int main() {
    processStack();
    return 0;
}

