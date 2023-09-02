#include <stdio.h>
#include "calc.h"

#define MAXVAL 100              /* maximum depth of val stack */

static int sp = 0;                     /* next free stack position */
static double val[MAXVAL];             /* val stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value form stack */
double pop(void) {
    if (0 < sp) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0;
    }
}
