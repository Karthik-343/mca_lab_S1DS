#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    char str[MAX_STRINGS][MAX_LENGTH];
    int n, i, j;
    char temp[MAX_LENGTH];
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d strings:\n", n);
    for(i = 0; i < n; i++) {
        fgets(str[i], MAX_LENGTH, stdin);
        int len = strlen(str[i]);
        if(len > 0 && str[i][len - 1] == '\n') {
            str[i][len - 1] = '\0';
        }
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(strcmp(str[j], str[j + 1]) > 0) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    printf("\nStrings in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}

