/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions. */

#include <stdio.h>

int rightrot(int x, int n) {
    int aux;


    aux = x;

    aux = aux << n;     /* shift left aux */
    aux = aux & x;      /* mask aux to width in bits of x */

    x = x >> n;         /* shift right x */

    return x | aux;     /* join x and aux */
}

/* Test */

#define nro 8

int main() {
    printf("Original %d, rotate %d", nro, rightrot(nro,2));

    return 0;
}
