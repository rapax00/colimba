/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types. */

#include <stdio.h>
#include <limits.h>

int main() {
    printf("With library limits.h\n");
    printf("---\n");
    printf("unsigned char: %u, %u\n", 0, UCHAR_MAX);
    printf("signed char: %d, %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("---\n");
    printf("unsigned short: %u, %u\n", 0, USHRT_MAX);
    printf("signed short: %d, %d\n", SHRT_MIN, SHRT_MAX);
    printf("---\n");
    printf("unsigned int: %u, %u\n", 0, UINT_MAX);
    printf("signed int: %d, %d\n", INT_MIN, INT_MAX);
    printf("---\n");
    printf("unsigned long: %u, %u\n", 0, LONG_MAX);
    printf("signed long: %d, %ld\n", LONG_MIN, LONG_MAX);
    printf("\n");

    unsigned char max_uchar = (unsigned char) ~0;
    unsigned short max_ushort = (unsigned short) ~0;
    unsigned int max_uint = (unsigned int) ~0;
    unsigned long max_ulong = (unsigned long) ~0;

    printf("Manually\n");
    printf("---\n");
    printf("unsigned char: %u, %u\n", max_uchar - max_uchar, max_uchar);
    printf("signed char: %d, %d\n", max_uchar - (max_uchar >> 1), max_uchar - (max_uchar - (max_uchar >> 1)));
    printf("---\n");
    printf("unsigned short: %u, %u\n", max_ushort - max_ushort, max_ushort); /* I dont know why not it get- in the begin */
    printf("signed short: %d, %d\n", (max_ushort - (max_ushort >> 1)), max_ushort - (max_ushort - (max_ushort >> 1)));
    printf("---\n");
    printf("unsigned int: %u, %u\n", max_uint - max_uint, max_uint);
    printf("signed int: %d, %d\n", (max_uint - (max_uint >> 1)), max_uint - (max_uint - (max_uint >> 1)));
    printf("---\n");
    printf("unsigned long: %lu, %lu\n", max_ulong - max_ulong, max_ulong);
    printf("signed long: %ld, %ld\n", (max_ulong - (max_ulong >> 1)), max_ulong - (max_ulong - (max_ulong >> 1)));

    return 0;
}
