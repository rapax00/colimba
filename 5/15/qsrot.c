#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

/* qsort: sort v[left]...v[right] into increasing order */
void qsortt(void *v[], int left, int right, int (*comp)(void *, void*, int), int (*direction)(int), int casedist) {
    int i, last;
    void swap(void *v[], int, int);
    void swap(void *v[], int, int);

    if (right <= left) {        /* do nothing if array contains */
        return;                 /* fewer than two elements */
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (0 < direction(comp(v[i], v[left], casedist))) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsortt(v, left, last - 1, comp, direction, casedist);
    qsortt(v, last + 1, right, comp, direction, casedist);
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2, int casedist) { /* NOTE: casedist is useless but necessary? so that the definition of numcmp and strcmpp are same */
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

int strcmpp(char *s1, char *s2, int casedist) {
    int i, a, b;

    if (casedist) {
        for (i = 0; (a = tolower(s1[i])) == (b = tolower(s2[i])) && s1[i] != '\0' && s2[i] != '\0'; i++) {
            ;
        }
    } else {
        for (i = 0; (a = s1[i]) == (b = s2[i]) && s1[i] != '\0' && s2[i] != '\0'; i++) {
            ;
        }
    }

    if (a < b) {
        return 1;
    } else if (b < a) {
        return -1;
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
