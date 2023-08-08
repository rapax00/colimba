#include "functions.h"

/* strncpy: copy at most n characters of string t to s; return s.
Pad with '\0' s if t has fewer than n characters */
char *strncpy(char s[], char t[], int n) {
    char *a = s;
    char *limit = t + n;    /* set limit to copy form t to s */

    while (limit != t) {
        *s++ = *t++;
        if ('\0' == *t ) {
            while ('\0' != *s) {
                *s++ = '\0';
            }
            return a;
        }
    }

    return a;
}

/* strncat: concatenate at most n characters of string t to string
s, terminate s with '\0'; return s. */
char *strncat(char s[], char t[], int n) {
    char *a = s;

    while ('\0' != *s) {    /* to final of s */
        s++;
    }

    char *limit = s + n;

    while (s != limit && '\0' != *t) {
        *s++ = *t++;
    }

    *s = '\0';

    return a;
}

/* strncmp: compare at most n characters of string s to string t;
return <0 if s<t, 0 if s==t, or >0 if s>t. */
int strncmp(char s[], char t[], int n) {
    int i = 0;
    while (i++ < n - 1 && *s++ == *t++) {
        ;
    }
    if (*s < *t) {
        return *s - *t;
    } else if (*t < *s) {
        return *s - *t;
    } else {
        return *(s - 1) - *(t - 1);
    }
}

/* Dude: why need return s in strncpy and strncat if I can modify the array itself? */
