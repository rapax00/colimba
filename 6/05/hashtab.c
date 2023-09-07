#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashtab.h"
#include "strdup.h"

#define HASHSIZE 101

struct nlist *hashtab[HASHSIZE];

/*  hash: from hash value for string s */
unsigned int hash(char *s) {
    unsigned int hashval;

    for(hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/*  lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0) {
            return np; /* found */
        }
    }

    return NULL;    /* not found */
}

/*  install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned int hashval;

    if((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL) {
            printf("error: %s is NULL", (np == NULL)? "pointer": "name");
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;  /* already there */
    } else {
        free((void *) np->defn);    /* free previous defn */
    }

    if((np->defn = strdup(defn)) == NULL) {
        perror("error: defn is NULL");
        return NULL;
    }

    return np;
}

/*  undef: remove name and definition of str from hashtab
    NOTE: I define "hashchain" with the "list" of nlist with equal hash in hashtab */
void undef(char *str) {
    struct nlist *finder(struct nlist *, void *);   /* explain down*/

    struct nlist *ntd, *naux1, *naux2;              /* ntd: node to delete */

    if((ntd = lookup(str)) != NULL) {
        naux1 = finder(ntd, NULL);                  /* find the last one not NULL nlist of hashchain and save in naux1 */
        naux1->next = hashtab[hash(str)];           /* establish next of naux1 that begin of hashchain, now is formed an "endless cycle" */
        hashtab[hash(str)] = ntd->next;             /* assign next of ntd as begin of hashchain */
        naux2 = finder(hashtab[hash(str)], ntd);    /* find previous node to ntd */
        naux2->next = NULL;                         /* cut off the endless cycle assign NULL to this previous node to ntd */
        free(ntd);                                  /* delete ntd */
    }
}

/*  finder: return previous node of nwant beginning in np
    nwant usually is:
    - NULL pointer or,
    - specific nlist pointer */
struct nlist *finder(struct nlist *np, void *nwant) {
    if(np->next == nwant) {
        return np;  /* already found */
    } else {
        return finder(np->next, nwant); /* find recursively */
    }
}

/*  printhashchain: print hashchain beginning for node
    NOTE: node is not NULL */
void printhashchain(struct nlist *node) {
    if(node->next != NULL) {
        printhashchain(node->next);
    }
    printf("\t| %10s | %10s |\n", node->name, node->defn);
}

/*  printarray: pirnt hashtab by accessing for each hashchain*/
void printarray(void) {
    int i = HASHSIZE;

    printf("\t| %10s | %10s |\n", "NAME", "DEFN"); /* header */

    while(i--) {
        if(hashtab[i] != NULL) {
            printhashchain(hashtab[i]); /* I dont understand why dont I can hashtab++ instead of hashtab[i] */
        }
    }
}

/*  Duda:
    Que es "mejor visto" o "mas facil" de leer, interpretar, etc.
    Que se declare una funcin dentro de otra función (como en las linea 65) y luego se la defina. Como hice con undef() y finder()
    o
    Que primero se defina la funcion antes de usarla en otra. Como hice con printhashchain() y pŕintarray()
*/
