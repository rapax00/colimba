#include <string.h>

#include "strdup.h"

char *strdup(char *s) {
    char *dup = (char *) malloc(strlen(s) + 1);

    if(dup != NULL) {
        strcpy(dup, s);
    }

    return dup;
}
