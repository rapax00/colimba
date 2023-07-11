/* Exercise 1-16. Revise the main routine of the longest-line program so it will
correctly print the length of arbitrarily long input lines, and as much as possible
of the text. */

#include <stdio.h>

#define MAXLINE 15

int getline(char line[], int maxline);

int main() {
    int lineLenght;
    char line[MAXLINE+2];

    while((lineLenght = getline(line, MAXLINE+2)) > 0) {
        printf("La linea tiene %d caracteres, y lo maximo que se puede impirmir es:\n%s", lineLenght, line);
    }

    return 0;
}

int getline(char s[], int lim){
    int c, i, count = 0;

    for (i = 0; i < lim-1; ++i) { /* limpia el array */
        s[i] = 0;
    }

    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n')) {
        if (i < lim-2) {
            s[i] = c;
            ++i;
        } else if (i < lim-1) {
            s[i] = '\n';
            s[++i] = '\0';
        }

        ++count;
    }

    return count;
}
