/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.*/

#include <stdio.h>

#define MAXSIZE 1000

int getline(char s[], int lim);

int main() {
    int k;
    char line[MAXSIZE+1]; /* +1 for \0 */

    while ((k = getline(line, MAXSIZE+1)) > 0){
            printf("%s.", line);
    }

    return 0;
}

int getline(char s[], int lim){
    int c, i = 0, count = 0;

    while (((c = getchar()) != '\n') && c != EOF) {
        if (i < lim-1) {
            s[i] = c;
            ++i;
        }
        ++count;
    }

    if (0 < i) {
        --i;
        --count;

        while ((s[i] == ' ') || (s[i] == '\t')) {
            --i;
            --count;
        }

        ++i;
        s[i] = '\0';
    }

    return count;
}
