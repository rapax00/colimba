/* Exercise 5-2. Write getf loat, the floating-point analog of getint. What
type does getf loat return as its function value? */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "getch.h"

#define SIZE 100

int getint(double *pn);

int main(void) {
    int i, n, value;
    double array[SIZE];

    for (n = 0; n < SIZE && (value = getint(&array[n])) != EOF && 0 != value; n++) {
        ;
    }

    for (i = 0; i < n; i++) {
        printf("index: %3d, address: %18p, number: %10.8g\n", i, array+i, *(array+i));
    }

    return 0;
}

/* getint: get next integer from input into *pn
return EOF: end of input
return 0: it's not a number
return postive value: input is a valid number */
int getint(double *pn) {
    int c, sign, i;

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

    /* recive input (integer) */
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
    }
    /* decimal */
    if ('.' == c) {
        for (i = 1; isdigit(c = getch()); i++) {
            *pn += (c - '0') / (pow(10.0, i));
        }
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
