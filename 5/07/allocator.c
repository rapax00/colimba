#include <stdio.h>
#include "functions.h"

#define ALLOCSIZE 1000  /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n) { /* return pointer to n characters */
    if (n <= allocbuf + ALLOCSIZE - allocp) {    /* it fits n stuffs in array*/
        allocp += n;
        return allocp - n;
    } else {    /* not enough room */
        return 0;
    }
}

void afree(char *p) {   /* free storage pointed to by p */
    if (allocbuf <= p && p < allocbuf + ALLOCSIZE) {    /* if p is on allocbuf array */
        allocp = p;
    }
}
