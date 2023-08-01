#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

#define MAX 100
#define BUFSIZE 100

static char buf[BUFSIZE];              /* buffer for ungetch */
static int bufp = 0;                   /* next free position in buf */

int getop(char s[]) {
    int i, c;

    /* Blank jumping */
    while (' ' == (s[0] = c = getch()) || '\t' == c) {
        ;
    }
    s[1] = '\0';

    if ('\n' == c) {
        return c;
    }

    /* Non-digit manipulation */
    if (!isdigit(c)) {                                                                          /* is not a digit*/
        char aux = c;
        if (isdigit(c = getch())) {                                                             /* record in c the next char */
            if (BUFSIZE <= bufp) {                                                              /* if c is a digit, then the input is a number with digit, ungetch for read in next call of getop*/
                printf("ungetch: too many characters");
            } else {
                buf[bufp++] = c;
            }
        } else if (' ' == c || '\t' == c || '\n' == c) {                                        /* if c is a blank, aux is a operator */

            if (c != EOF) {
                if (BUFSIZE <= bufp) {
                    printf("ungetch: too many characters");
                } else {
                    buf[bufp++] = c;
                }
            }

            return aux;                                                                         /* return operator */
        } else if (!isdigit(c)) {                                                               /* if c is a letter, then the input is a command or invalid input */
            i = 0;
            s[++i] = c;
            while (!isdigit(s[++i] = c = getch()) && ' ' != c && '\t' != c && '\n' != c) {      /* read the input  */
                ;
            }
            s[i] = '\0';

            if (c != EOF) {
                if (BUFSIZE <= bufp) {
                    printf("ungetch: too many characters");
                } else {
                    buf[bufp++] = c;
                }
            }

            ungets(s);

            return detectCommand();                                                            /* detect if the s is a command or invalid input*/
        }
    }

    /* Digit manipulation */
    i = 0;
    if (isdigit(c)) {                                                                           /* si es un numero */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if ('.' == c) {                                                                             /* si detecta un punto sigue metindo numeros */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';

    if (c != EOF) {
        if (BUFSIZE <= bufp) {
            printf("ungetch: too many characters");
        } else {
            buf[bufp++] = c;
        }
    }

    return NUMBER;
}

int getch(void) {               /* get a (possibly pushed back) character */
    return (0 < bufp) ? buf[--bufp] : getchar();
}

/* ungets: push to entire string to stack
Note: ungets() doesn't need know buf and bufp */
void ungets(char s[]) {
    int i;
    for (i = strlen(s); 0 <= i; i--) {
        if (BUFSIZE <= bufp) {
            printf("ungetch: too many characters");
        } else {
            buf[bufp++] = s[i];
        }
    }
}

/* detectCommand: detect if s is a command valid */
int detectCommand() {
    int i, c;
    char s[MAXOP];

    for (i = 0; '\0' != (c = getch()); i++) {
        s[i] = c;
    }
    s[i] = c;

    if (strcmp(s, "top") == 0) {
        return TOP;
    } else if (strcmp(s, "swp") == 0) {
        return SWP;
    } else if (strcmp(s, "clr") == 0) {
        return CLR;
    } else if (strcmp(s, "sin") == 0) {
        return SIN;
    } else if (strcmp(s, "exp") == 0) {
        return EXP;
    } else if (strcmp(s, "pow") == 0) {
        return POW;
    } else {
        return ERR;
    }
}
