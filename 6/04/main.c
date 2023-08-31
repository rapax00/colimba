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
    int occurs;    /* number if occurrences per line */
    struct word *left;          /* left child */
    struct word *right;         /* right child */
};

struct word *addWord(struct word *, char *);
struct word *walloc(void);
char *strdup(char *);
void wordsprint(struct word *);
struct word *aftt(struct word *, struct word *);
struct word *orderTree(struct word *, char *, int);

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
            root = addWord(root, w);
        }
    }

    printf("-------------\n");
    wordsprint(root);
    printf("-------------\n");

    struct word *aux = NULL;

    aux = aftt(root, aux);

    printf("aux----------\n");
    wordsprint(aux);
    printf("-------------\n");

    return 0;
}

struct word *addWord(struct word *p, char *s) {
    int cond;

    if(p == NULL) {             /* a new word has arrived */
        p = walloc();           /* make a new node */
        p->str = strdup(s);
        p->occurs = 1;
        p->left = p->right = NULL;
    } else if(0 == (cond = strcmp(p->str, s))) {   /* repeated word */
        p->occurs++;
    } else if(cond > 0) {                           /* less than into left subtree */
        p->left = addWord(p->left, s);
    } else {                                        /* greater than into right subtree */
        p->right = addWord(p->right, s);
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

void wordsprint(struct word *p) {
    if(p != NULL) {
        wordsprint(p->left);
        printf("\t%d %s\n", p->occurs, p->str);
        wordsprint(p->right);
    }
}

struct word *aftt(struct word *root, struct word *rootmdfy) {
    if(root != NULL) {
        rootmdfy = aftt(root->left, rootmdfy);
        rootmdfy = orderTree(rootmdfy, root->str, root->occurs);
        rootmdfy = aftt(root->right, rootmdfy);
    }
    return rootmdfy;
}

struct word *orderTree(struct word *root, char *str, int oc) {
    if(NULL == root) {
        root = walloc();
        root->occurs = oc;
        root->str = (char *) malloc(strlen(str) + 1);
        strcpy(root->str, str);
        root->left = root->right = NULL;
    } else {
        if(oc < root->occurs) {
            root->left = orderTree(root->left, str, oc);
        } else if(root->occurs < oc) {
            root->right = orderTree(root->right, str, oc);
        } else {
            if(0 <= (strcmp(str, root->str))) {
                root->right = orderTree(root->right, str, oc);
            } else {
                root->left = orderTree(root->left, str, oc);
            }
        }
    }

    return root;
}
