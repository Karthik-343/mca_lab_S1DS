#include <stdio.h>
#include <string.h>

int main() {
    char str[100],temp;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

	int left = 0, right = len - 1;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}

