#include <stdio.h>

void* memset(void* str, int c, size_t n) {
    // unsigned char* ptr = (unsigned char*) str;
    char* ptr = (char*) str;

    for(int i = 0; i < n; i++) {
        *ptr++ = c;
    }

    return str;
}

int main() {
    // input 1
    char str[] = "This is string.h library function.";
    memset(str, '$', 7);

    // input 2
    // char str[] = "Hello word.";
    // memset(str, '0', 1);

    printf("%s\n", str);

    return 0;
}