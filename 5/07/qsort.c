#include <stdio.h>
#include "functions.h"

/* swap: interchange v[i] and v[j] */
static void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;

    if (right <= left) {    /* do nothing if array contains fewer than two elements */
        return;
    }

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
