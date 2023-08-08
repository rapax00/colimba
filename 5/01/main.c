/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a
valid representation of zero. Fix it to push such a character back on the input. */

#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define SIZE 100

int getint(int *pn);

int main(void) {
    int i, n, array[SIZE], value;

    for (n = 0; n < SIZE && (value = getint(&array[n])) != EOF && 0 != value; n++) {
        ;
    }

    for (i = 0; i < n; i++) {
        printf("index: %3d, address: %18p, number: %10d\n", i, array+i, *(array+i));
    }

    return 0;
}

/* getint: get next integer from input into *pn
return EOF: end of input
return 0: it's not a number
return postive value: input is a valid number */
int getint(int *pn) {
    int c, sign;

    /* skip white spaces */
    while (isspace(c = getch())) {
        ;
    }

    /* it's not a number */
    if (!isdigit(c) && EOF != c && '+' != c && '-' != c ) {
        return 0;
    }

    /* sign */
    sign = ('-' == c) ? -1 : 1;
    if ('-' == c || '+' == c) {
        c = getch();
    }
    if (!isdigit(c)) {   /* if next char of sign is not a number push it to input */
        ungetch(c);
    }

    /* recive input */
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;


    /* "eat" all non numbers after a number or minus*/
    while (!isdigit(c) && EOF != c && '-' != c ) {
        c = getch();
    }
    if (isdigit(c) || '-' == c ){   /* if "accidentally eat" a number, ungetch or minus */
        ungetch(c);
    }

    return c;
}
