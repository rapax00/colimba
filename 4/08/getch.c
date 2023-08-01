#include <stdio.h>
#include <string.h>

#define BUFSIZE 1

static char buf[BUFSIZE];              /* buffer for ungetch */
static int bufp = 0;                   /* next free position in buf */
static char cosa;
int state = 0;

int getch(void) {               /* get a (possibly pushed back) character */
    if (state) {
        state = 0;
        return cosa;
    } else {
        return getchar();
    }
}

void ungetch(int c) {           /* push character back on input */
    if (state) {
        printf("ungetch: too many characters");
    } else {
        cosa = c;
    }
}
