/* Exercise 6-3. Write a cross-referencer that prints a list of all words in a docu-
ment, and, for each word, a list of the line numbers on which it occurs. Remove
noise words like "the," "and," and so on. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getword.h"

#define MAXWORD 100
#define MAXLINES 1000

struct word {
    char *str;                  /* word */
    int lineCount[MAXLINES];    /* number if occurrences per line */
    struct word *left;          /* left child */
    struct word *right;         /* right child */
};

struct word *addWord(struct word *, char *, int);
struct word *walloc(void);
char *strdup(char *);
void wordsprint(struct word *, int);
void printlist(struct word *p, int);

int main(void) {
    char w[MAXWORD];
    int c;
    int numLine = 0;
    struct word *root;

    root = NULL;
    while((c = getword(w, MAXWORD)) != EOF && numLine < MAXLINES) {
        if(c == '\n') {
            numLine++;
        } else {
            root = addWord(root, w, numLine);
        }
    }

    wordsprint(root, numLine);

    return 0;
}

struct word *addWord(struct word *p, char *s, int numOfLine) {
    int cond;

    if(p == NULL) {             /* a new word has arrived */
        p = walloc();           /* make a new node */
        p->str = strdup(s);
        p->lineCount[numOfLine] = 1;
        p->left = p->right = NULL;
    } else if(0 == (cond = strcmp(p->str, s))) {   /* repeated word */
        p->lineCount[numOfLine] = 1;
    } else if(cond > 0) {                           /* less than into left subtree */
        p->left = addWord(p->left, s, numOfLine);
    } else {                                        /* greater than into right subtree */
        p->right = addWord(p->right, s, numOfLine);
    }

    return p;
}

struct word *walloc(void) {
    return (struct word *) malloc(sizeof(struct word));
}

char *strdup(char *s) {
    char *p;

    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */

    if(p != NULL) {
        strcpy(p, s);
    }

    return p;
}

void wordsprint(struct word *p, int lines) {
    if(p != NULL) {
        wordsprint(p->left, lines);
        printf("%s ", p->str);
        printlist(p, lines);
        wordsprint(p->right, lines);
    }
}

void printlist(struct word *p, int lines) {
    int i;

    printf("\tlines that occurs:");
    for(i = 0; i < lines; i++) {
        if(p->lineCount[i]) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");
}
