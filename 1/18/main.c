/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.*/

#include <stdio.h>

#define MAXSIZE 1000

int getline(char s[], int lim);

int main() {
    char c[MAXSIZE];

    while (getline(c, MAXSIZE)){
        printf("El input: %s", c);
    }

    return 0;
}

int getline(char s[], int lim){
    int c, i;

    for (i = 0; (i<lim-1) && ((c = getchar())!=EOF) && (c!='\n'); ++i) {
        s[i] = c;
    }

    printf("valor de c %c", c);

    --i; /* para posicionarse en el ultimo caracter del input */

    while ((s[i] == ' ') || (s[i] == '\t')) {
            --i;
    }

    ++i;
    s[i] = '}'; /* para ver donde esta el final del input */
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';

    return i;
}
