#include <ctype.h>
#include <stdio.h>
#include "getch.h"

void detectSpaces(void);
void detectUnderscore(char *);
void detectQuotes(void);
void detectComments(void);
void detectPreprocessor(void);

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    detectSpaces();
    detectQuotes();
    detectSpaces();
    detectComments();
    detectSpaces();
    detectPreprocessor();
    detectSpaces();
    detectUnderscore(w);

    return word[0];
}

/* detectSpace: skip spaces */
void detectSpaces(void) {
    int c;

    while(isspace((c = getch()))) {
        ;
    }
    ungetch(c);

    return;
}

/* follow functions ungetch space */
void detectQuotes(void) {
    int c;

    if ('"' == (c = getch())) {
        while((c = getch()) != '"') {
            ;
        }
        return;
    }
    ungetch(c);

    return;
}

void detectComments(void) {
    int c;

    if ('/' == (c = getch())) {
        while((c = getch()) != '/') {
            ;
        }
        return;
    }
    ungetch(c);

    return;
}

void detectPreprocessor(void) {
    int c;

    if ('#' == (c = getch())) {
        while(!isspace(c = getch())) {
            ;
        }
        return;
    }
    ungetch(c);

    return;
}

/* detectUnderscore: have 3 posbile scenaries
1. str is EOF
2. str is space
3. str is valid C key */
void detectUnderscore(char *str) {
    int c;
    char *s = str;

    if((c = getch()) != EOF && c != '_') {
        *s++ = c;
    }
    if(!isalpha(c)) {   /* handle _ckey */
        while(!isspace(c = getch()) && c != EOF) {
            ;
        }
        *s++ = c;
        *s = '\0';
        return;
    }
    if(isalpha(c)) {   /* handle ckey_, ckey_ckey and non-underscore */
        while(!isspace(c = getch()) && c != EOF && c != '_') { /* read letters previous _ */
            *s++ = c;
        }
        if(isspace(c)) { /* if the last of one char is space, that is a valid C key */
            *s = '\0';
            return;
        } else if ('_' == c) {  /* if the last of one char is _, that is a invalid word */
            while(!isspace(c = getch()) && c != EOF) {
                ;
            }
            s[0] = c;
            *++s = '\0';
            return;
        }
    }
}
