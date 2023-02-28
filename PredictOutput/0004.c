#include <stdio.h>

char* getString_1() {
    char* str = "Nice test for strings.";
    return str;
}

char* getString_2() {
    char str[] = "Will I be printed?";
    return str;
}
 
int main() {
    printf("%s \n", getString_1());
    printf("%s \n", getString_2());
    getchar();
   
    return 0;
}