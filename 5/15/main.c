/* Exercise 5-15. Add the option -f to fold upper and lower case together, so that
case distinctions are not made during sorting; for example, a and A compare
equal. */

#include <stdio.h>
#include <string.h>
#include "functions.h"

#define MAXLINES 5000    /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int main(int argc, char *argv[]) {
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int order = 0;      /* 1 if reverse order sort */
    int casedist = 0;   /* 1 if non distinction entre upper and lower case*/

    ++argv; /* skip ./main */
    --argc;
    --argc; /* skip qsort */

    while (0 < argc && (*++argv)[0] == '-') {
        --argc;
        switch ((*argv)[1]) {
        case 'n':
            numeric = 1;
            break;
        case 'r':
            order = 1;
            break;
        case 'f':
            casedist = 1;
        }
    }

    if (0 < (nlines = readlines(lineptr, MAXLINES))) {
        printf("-------------------------------------------------\n");
        printf("INPUT:\n");
        writelines(lineptr, nlines);
        printf("-------------------------------------------------\n");
        qsortt((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *, int))(numeric ? numcmp : strcmpp), (int (*)(int))(order ? reversee : normal), casedist);
        printf("-------------------------------------------------\n");
        printf("OUTPUT:\n");
        writelines(lineptr, nlines);
        printf("-------------------------------------------------\n");
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
