/* Exercise 5-14. Modify the sort program to handle a -r flag, which indicates
sorting in reverse (decreasing) order. Be sure that -r works with -n. */

#include <stdio.h>
#include <string.h>
#include "functions.h"

#define MAXLINES 5000    /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int main(int argc, char *argv[]) {
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int order = 0;      /* 1 if reverse order sort */

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
            printf("entro\n");
            order = 1;
            break;
        }
    }

    if (0 < (nlines = readlines(lineptr, MAXLINES))) {
        printf("-------------------------------------------------\n");
        printf("INPUT:\n");
        writelines(lineptr, nlines);
        printf("-------------------------------------------------\n");
        qsortt((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), (int (*)(int))(order ? reversee : normal));
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
