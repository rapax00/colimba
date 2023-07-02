/* Exercise 1-17. Write a program to print all input lines that are longer than 80
characters. */

#include <stdio.h>

#define MAXSIZE 1000

int getline(char s[], int lim);

int main(){
    char line[MAXSIZE], length;

    length = 0;

    while(length = getline(line, MAXSIZE)) {
        if (length > 80) {
            printf("El input larguisimo: %s",line);
        } else {
            printf("El input es menor a 80 caracteres\n");
        }
    }

    return 0;
}

int getline(char s[], int lim){
    int c, i;

    for (i = 0; (i<lim-1) && ((c = getchar())!=EOF) && (c!='\n'); ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
