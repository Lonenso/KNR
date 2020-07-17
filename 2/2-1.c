#include <stdio.h>
#include <limits.h>

int main() {
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("signed long min = %d\n", LONG_MIN);
    printf("signed long max = %d\n", LONG_MAX);

    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);
    printf("-----------------------\n");
    printf("~0: %d\n", ~0);
    printf("(unsigned char)~0: %d\n", (unsigned char)~0);
    printf("(unsigned char)~0 >> 1: %d\n", (unsigned char)~0>>1);
    printf("(char)((unsigned char)~0 >> 1): %d\n", (char)((unsigned char)~0 >> 1));
}