#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h">

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
    if (!isdigit(c)) {                                                                          /* si no es un digito */
        char aux = c;
        if (isdigit(c = getch())) {                                                             /* lo que sigue despues es un digito */
            ungetch(c);                                                                         /* entonces el input es un nro con signo */
        } else if (' ' == c || '\t' == c || '\n' == c) {

            if (c != EOF) {
                ungetch(c);
            }

            return aux;                                                                         /* es un operador */
        } else if (!isdigit(c)) {                                                               /* si lo que siguen despues es una letra */
            i = 0;
            s[++i] = c;
            while (!isdigit(s[++i] = c = getch()) && ' ' != c && '\t' != c && '\n' != c) {      /* mientras siga recibiendo letras */
                ;
            }
            s[i] = '\0';

            return detectCommand(s);                                                            /* es un comando */
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

int detectCommand(char s[]) {
    if (strcmp(s, "top") == 0) {
        return TOP;
    } else if (strcmp(s, "swp") == 0) {
        return SWP;
    } else if (strcmp(s, "clr") == 0) {
        return CLR;
    } else {
        return ERR;
    }
}
