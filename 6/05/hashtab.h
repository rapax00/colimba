#ifndef HASHTAB_H_INCLUDE
#define HASHTAB_H_INCLUDE

struct nlist {              /* table entry: */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};

struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
void printarray(void);

#endif HASHTAB_H_INCLUDE
