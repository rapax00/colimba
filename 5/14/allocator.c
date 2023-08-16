#include <stdio.h>
#include "functions.h"

static char allocbuf[MAXLINES * MAXLEN];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n) { /* return pointer to n characters */
    if (n <= allocbuf + MAXLINES * MAXLEN - allocp) {    /* it fits n stuffs in array*/
        allocp += n;
        return allocp - n;
    } else {    /* not enough room */
        return 0;
    }
}
