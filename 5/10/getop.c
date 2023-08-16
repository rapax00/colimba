#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

int getop(char s[], char arg[]) {
    int i, c;

    if (NULL == arg) {      /* end of program */
        return NULL;
    }

    /* sign, operator or invalid input manipulation */
    if (!isdigit(arg[0])) {                  /* first char of the array arg */
        if (isdigit(arg[1])) {               /* if second char is a digit then the input is a number with sign */
            strcpy(s, arg);
            return NUMBER;
        } else if ('\0' == arg[1]) {        /* if  second char is 0 is a operator or invalid letter, problem of main  */
            strcpy(s, arg);
            return arg[0];
        } else if (strcmp(arg, "sin") == 0) {
            return SIN;
        } else if (strcmp(arg, "exp") == 0) {
            return EXP;
        } else if (strcmp(arg, "pow") == 0) {
            return POW;
        } else {
            strcpy(s, arg);
            return ERR;
        }
    }

    /* unsigned number manipulation */
    if (isdigit(arg[0])) {
        strcpy(s, arg);
        return NUMBER;
    }
}
