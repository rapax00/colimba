/* Exercise 1-19. Write a function reverse(s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char line[], int length, char rev[]);

int main(){
    char line[MAXLINE];
    int length;

    while((length = (getline(line, MAXLINE))) > 0){
        char rev[length];
        reverse(line, length, rev);

        printf("El largo es %d. El input es: \"%s\". Su reverso: \"%s\"\n",length, line, rev);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim){
    int c, i;

    for (i = 0; (i<lim-1) && ((c = getchar())!=EOF) && (c!='\n'); ++i){
        s[i] = c;
    }

    s[i] = '\0';

    return i;
}

void reverse(char line[], int length, char rev[]){
    int i;

    for(i = length; i > 0; --i){
        rev[length-i] = line[i-1];
    }

    rev[length] = '\0';
}
