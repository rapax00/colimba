#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED

#define MAXLEN 1000         /* max length of any input line */
#define MAXLINES 5000

char *alloc(int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsortt(void *lineptr[], int left, int right, int (*comp)(void *, void *), int (*direction)(int));

int numcmp(char *, char *);
int normal(int x);
int reversee(int x);

#endif // FUNCTIONS_INCLUDED
