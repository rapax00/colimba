/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged. */

int setbits(int x, int p, int n, int y) {
    int aux;

    aux = (1 << n) - 1;     /* define number of bits that I get of y */

    int yaux = y & aux;     /* obtain finaly bits to put in x */

    yaux = yaux << (p-n);   /* positions in the p position the bits to put in x */

    return x | yaux;        /* put the bits in x */
}

/* Test*/
/*
int main() {
    printf("%d", setbits(42, 3, 2, 11));

    return 0;
}
*/
