/* Exercise 6-5. Write a function undef that will remove a name and definition
from the table maintained by lookup and install. */

#include <stdio.h>
#include "hashtab.h"

#define MAXLEN 100

int getline(char *, int);

int main(void) {
    char name[MAXLEN];
    char defn[MAXLEN];

    printf("write name\n");
    while(getline(name, MAXLEN) != EOF) {
        printf("write defn\n");
        getline(defn, MAXLEN);
        install(name, defn);
        printf("write name\n");
    }

    printarray();

    undef("hola");

    printf("-----------------------------------\n");

    printarray();

    return 0;
}

int getline(char *s, int lim) {
    int c = 0;

    while((c = getchar()) != 'EOF' && c != '\n' && lim--) {
       *s++ = c;
    }

    *s = '\0';

    return c;
}
