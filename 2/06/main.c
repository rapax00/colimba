/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged. */

#include <stdio.h>

int setbits(int x, int p, int n, int y) {
    int aux;

    aux = (1 << n) - 1;     /* define number of bits that I get of y */

    int yaux = y & aux;     /* obtain finaly bits to put in x */

    yaux = yaux << (p-n);   /* positions in the p position the bits to put in x */

    return x | yaux;        /* put the bits in x */
}

void pb(unsigned x) {
    int size = sizeof(x) * 8;

    char bits[size];

    int i;
    for (i = 0; i < size; i++) {
        bits[i] = x & (1u << i) ? '1' : '0';
    }

    for (i = size; i; i--) {
        printf("%c", bits[i - 1]);
    }

    printf("\n");
}

/* Test*/
int main() {
    int result = setbits(256, 8, 8, 127);
    printf("%d\n", result);
    pb(result);

    return 0;
}
