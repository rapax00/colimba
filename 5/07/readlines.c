#include <stdio.h>
#include <string.h>
#include "functions.h"

/* getline: read a line into s, return length */
int getline(char s[], int lim){
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }

    if ((c=='\n') && (i>0)){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *aux) {
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (maxlines <= nlines || MAXLEN < len) {
            return -1;
        } else {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(aux, line);
            lineptr[nlines++] = aux;
            aux += len;
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
