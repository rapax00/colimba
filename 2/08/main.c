/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions. */

#include <stdio.h>

int rightrot(int x, int n) {
    int mask;

    mask = x;                               /* copy x in mask to manipulate*/

    mask = x << (sizeof(x) * 8 - n);        /* positioning the values to rotate in the correct site */

    x = x >> n;                             /* delete of x the values to rotate */

    return x | mask;                        /* join x (with less values to rotate) with mask (with values to rotate)*/
}

/* Test */
#define nro 8

int main() {
    printf("Original %d, rotate %d", nro, rightrot(nro,4));

    return 0;
}
