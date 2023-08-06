#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED

/* client */
#define MAXLINES 5000       /* max #lines to be stored */

int readlines(char *[], int);
void writelines(char *[], int);

void qsort(char *[], int, int);

/* client */
char *alloc(int);
void afree(char *);

#endif // FUNCTIONS_INCLUDED
