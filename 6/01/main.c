/* Exercise 6-1. Our version of getword does not properly handle underscores,
string constants, comments, or preprocessor control lines. Write a better ver-
sion. */

#include <stdio.h>
#include <ctype.h>
#include "functions.h"

int binsearch(char *, struct key *, int);

/* count C keywords */
int main(void) {
    printf("tam %d\n", NKEYS);
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            if (0 <= (n = binsearch(word, keytab, NKEYS))) {
                keytab[n].count++;
            }
        }
    }

    for(n = 0; n < NKEYS; n++) {
        if(0 < keytab[n].count) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, mid, high;

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        } else if(0 < cond) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}
