#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];              /* buffer for ungetch */
static int bufp = 0;                   /* next free position in buf */

int getch(void) {               /* get a (possibly pushed back) character */
    return (0 < bufp) ? buf[--bufp] : getchar();
}

void ungetch(int c) {           /* push character back on input */
    if (BUFSIZE <= bufp) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}

/* ungets: push to entire string to stack
Note: ungets() doesn't need know buf and bufp */
void ungets(char s[]) {
    int i;
    for (i = strlen(s); 0 <= i; i--) {
        ungetch(s[i]);
    }
}