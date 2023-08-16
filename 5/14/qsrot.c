#include <stdlib.h>
#include "functions.h"

/* qsort: sort v[left]...v[right] into increasing order */
void qsortt(void *v[], int left, int right, int (*comp)(void *, void*), int (*direction)(int)) {
    int i, last;
    void swap(void *v[], int, int);
    int normal(int x);
    int reversee(int x);

    if (right <= left) {        /* do nothing if array contains */
        return;                 /* fewer than two elements */
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (0 < direction(comp(v[i], v[left]))) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsortt(v, left, last - 1, comp, direction);
    qsortt(v, last + 1, right, comp, direction);
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2) {
        return -1;
    } else if (v2 < v1) {
        return 1;
    } else {
        return 0;
    }
}

int normal(int x) {
    return x;
}

int reversee(int x) {
    return -x;
}
