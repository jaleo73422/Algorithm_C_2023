#include <stdio.h>

char* strcpy(char* dest, const char* src) {
    char* ptr = dest;

    while (*src != '\0') {
        // *(dest++) = *src;
        *dest++ = *src++;
        // src++;
    }

    *dest = '\0';

    return ptr;
}

int main() {
    char dict[25];
    // char dict[] = "01234567891011";
    char src[] = "Hello word.";

    printf("%s\n", strcpy(dict, src));

    return 0;
}