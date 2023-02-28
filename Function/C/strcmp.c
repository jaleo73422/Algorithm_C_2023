#include <stdio.h>

int strcmp(const char* str1, const char* str2) {
    for(; *str1 != '\0' || *str2 != '\0'; str1++, str2++) {
        if (*str1 > *str2) {
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

    // input 2
    // char str1[] = "Abcdef";
    // char str2[] = "";

    // input 3
    // char str1[] = "";
    // char str2[] = "";

    // input 4
    char str1[] = "Abcdef";
    char str2[] = "Ab";

    // input 5
    // char str1[] = "A bcdef";
    // char str2[] = "Ab";

    int ans = strcmp(str1, str2);

    if (ans > 0) {
        printf("str1 > str2. \n");
    } else if (ans == 0) {
        printf("str1 = str2. \n");
    } else {
        printf("str1 < str2. \n");
    }

    return 0;
}