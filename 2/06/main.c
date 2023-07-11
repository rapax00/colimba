/* Exercise 2-7. Write a function invert ( x , p , n ) that returns x with the n bits
that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
the others unchanged.*/

#include <stdio.h>

int invert(int x, int p, int n) {
    int aux;

    aux = (1 << p) -1;      /* obtain distance p of bit to change */
    aux = aux >> (p - n);   /* set only bits to change */
    aux = aux << (p - n);   /* obtain distance and really bits to invert of x */

    return x ^ aux;
}

/* Test */
int main() {
    printf("%d", invert(32, 5, 3));

    return 0;
}
