#include <stdio.h>
#include <string.h>
#include "functions.h"

static char *lineptr[MAXLINES];     /* pointers to text lines */
static char *aux[MAXLEN];           /* auxiliar array to store temporally line read */

int main(void) {
    int nlines;     /* numbers of input lines read */

    if (0 <= (nlines = readlines(lineptr, MAXLINES, aux))) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


