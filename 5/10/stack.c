#include <stdio.h>
#include "functions.h"

static int sp = 0;                     /* next free stack position */
static double val[MAXVAL];             /* val stack */
static int sizeS = 0;

/* push: push f onto value stack */
int push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
        return ++sizeS;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value form stack */
double pop(void) {
    if (0 < sp) {
        sizeS--;
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
