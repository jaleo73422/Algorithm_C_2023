#include <stdio.h>

// int main() {
//    printf("%x \n", -1 << 1);
//    getchar();

//    return 0;
// }

int main() {
    // printf("%x \n", -1 << 1);
    printf("2147483647 -> %d \n", 2147483647);
    printf("-2147483648 -> %d \n", -2147483648);
    printf("2147483648 -> %d \n", 2147483648);
    printf("2147483648 -> %d \n", 2147483649);
    // printf("%d \n", -2147483647);
    // printf("%d \n", 2147483649);
    // printf("%d \n", 2147483650);
    getchar();
    
    return 0;
}

/*
32 bits
max integer in C (positive): 2,147,483,647
1000 0000 0000 0000 0000 0000 0000 0000 -> 2,147,483,647

min integer in C (negative): -2,147,483,648
0111 1111 1111 1111 1111 1111 1111 1111 -> -2,147,483,648

1 0000 0000 0000 0000 0000 0000 0000 0000 -> 4,294,967,296
1111 1111 1111 1111 1111 1111 1111 1111 -> 4,294,967,295
1111 1111 1111 1111 1111 1111 1111 1111
1 0000 0000 0000 0000 0000 0000 0000 0000

 1 -> 0000 ... 0001
-1 -> 1111 ... 1110 + 1 = 1111 ... 1111
(-1 < 1) -> 1111 ... 1110 -> 4,294,967,294

1111...111
*/