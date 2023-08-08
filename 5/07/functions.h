#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED

/* client */
#define MAXLINES 5000       /* max #lines to be stored */
#define MAXLEN 1000         /* max length of any input line */

int readlines(char *[], int, char *);
void writelines(char *[], int);

void qsort(char *[], int, int);

#endif // FUNCTIONS_INCLUDED
