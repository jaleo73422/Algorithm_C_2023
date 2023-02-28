#include <stdio.h>

int strncmp(const char* str1, const char* str2, int n) {
    for(int i = 0; (*str1 != '\0' || *str2 != '\0') && i < n; str1++, str2++, i++) {
        if(*str1 > *str2) {
            return 1;
        } else if(*str1 < *str2) {
            return -1;
        }
    }

    return 0;
}

int main() {
    // input 1
    // char str1[] = "Abcdef";
    // char str2[] = "a";
    // int ans = strncmp(str1, str2, 6);

    // input 2
    // char str1[] = "Abcdef";
    // char str2[] = "";
    // int ans = strncmp(str1, str2, 6);

    // input 3
    // char str1[] = "";
    // char str2[] = "";
    // int ans = strncmp(str1, str2, 1);

    // input 4
    // char str1[] = "Abcdef";
    // char str2[] = "Ab";
    // int ans = strncmp(str1, str2, 6);

    // input 5
    // char str1[] = "ABCdef";
    // char str2[] = "ABCDef";
    // int ans = strncmp(str1, str2, 4);

    // input 6
    char str1[] = "ABCdef";
    char str2[] = "ABCDef";
    int ans = strncmp(str1, str2, 3);

    if (ans > 0) {
        printf("str1 > str2. \n");
    } else if (ans == 0) {
        printf("str1 = str2. \n");
    } else {
        printf("str1 < str2. \n");
    }

    return 0;
}