#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;
    int detectCommand(char s[]);

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
            ungetch(c);                                                                         /* if c is a digit, then the input is a number with digit, ungetch for read in next call of getop*/
        } else if (' ' == c || '\t' == c || '\n' == c) {                                        /* if c is a blank, aux is a operator */

            if (c != EOF) {
                ungetch(c);
            }

            return aux;                                                                         /* return operator */
        } else if (!isdigit(c)) {                                                               /* if c is a letter, then the input is a command or invalid input */
            i = 0;
            s[++i] = c;
            while (!isdigit(s[++i] = c = getch()) && ' ' != c && '\t' != c && '\n' != c) {      /* read the input */
                ;
            }
            s[i] = '\0';

            if (c != EOF) {
                ungetch(c);
            }

            return detectCommand(s);                                                            /* detect if the s is a command or invalid input*/
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
        ungetch(c);
    }

    return NUMBER;
}

/* detectCommand: detect if s is a command valid */
int detectCommand(char s[]) {
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
    } else if (strcmp(s, "dup") == 0) {
        return DUP;
    } else {
        return ERR;
    }
}
