#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while(isspace(c = getch()) && c != '\n') {
        ;
    }

    if(c != EOF) {
        *w++ = c;
    }
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for( ; 0 < --lim; w++) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
