#include <stdio.h>

int a[5], pos = -1;

void insert(int e) {
    if (pos == 4) {
        printf("Array is full\n");
    } else {
        a[++pos] = e;
        printf("Inserted %d\n", e);
    }
}

void delete() {
    if (pos == -1) {
        printf("Array is empty\n");
    } else {
        printf("Deleted %d\n", a[pos--]);
    }
}

void sort() {
    if (pos == -1) {
        printf("Array is empty, cannot sort\n");
        return;
    }
    int i, j, temp;
    for (i = 0; i <= pos; i++) {
        for (j = 0; j < pos - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array sorted\n");
}

void search() {
    if (pos == -1) {
        printf("Array is empty\n");
        return;
    }
    int val, i, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &val);
    for (i = 0; i <= pos; i++) {
        if (a[i] == val) {
            printf("Element %d found at index %d\n", val, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found\n", val);
    }
}

void printArray() {
    int i;
    if (pos == -1) {
        printf("Array is empty\n");
        return;
    }
    printf("Current array: ");
    for (i = 0; i <= pos; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int menu() {
    int ch;
    printf("\n1 - Insert\n2 - Delete\n3 - Search\n4 - Sort\n5 - Print Array\n6 - Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processArray() {
    int ch, val;
    for (ch = menu(); ch != 6; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                sort();
                break;
            case 5:
                printArray();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

int main() {
    processArray();
    return 0;
}

