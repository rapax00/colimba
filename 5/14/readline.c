#include <stdio.h>
#include <string.h>
#include "functions.h"

/* getline: read a line into s, return length */
unsigned int getlinee(char s[], int lim){
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }
    s[i] = '\0';

    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getlinee(line, MAXLEN))) {
        if (maxlines <= nlines || (p = alloc(len + 1)) == NULL) {
            return -1;
        } else {
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while (0 < nlines--) {
        printf("%s\n", *lineptr++);
    }
}
