/* Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent. */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

double atof(char s[]);
int getline(char s[], int lim);

int main(void) {
    char s[MAX];
    double number;

    getline(s, MAX);

    number = atof(s);

    printf("String to convert is: %sFinally double is: %f", s, number);


    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int i, sign, signSciNot, lengthSciNot, j, stuff;          /* these are probably not the best names but they work */

    for (i = 0; isspace(s[i]); i++) {                   /* skip white space */
        ;
    }

    sign = ('-' == s[i]) ? -1 : 1;                      /* record sign */

    if ('+' == s[i] || '-' == s[i]) {                   /* skip sign */
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {               /* convert char to double */
        val = 10.0 * val + (s[i] - '0');
    }

    if ('.' == s[i]) {                                  /* skip colon */
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {             /* handle decimal */
        val = 10.0 * val + (s[i] - '0');                /* add decimal to int part */
        power *= 10.0;                                  /* with each decimal "add one ten" to after divide */
    }

    if ('e' == s[i] || 'E' == s[i]) {                   /* if detect scientific notation */
        i++;

        signSciNot = ('-' == s[i]) ? -1 : 1;            /* record the sign */

        if ('-' == s[i] || '+' == s[i]) {               /* skip the sign */
            i++;
        }

        for (lengthSciNot = 0; isdigit(s[i]); i++) {          /* read the "length" of scientific notation */
            lengthSciNot = lengthSciNot * 10 + (s[i] - '0');
        }

        for ( j = lengthSciNot, stuff = 1; j > 0; j--){       /* build stuff that is 1 multipli for "length" of scientific notation */
            stuff *= 10;
        }

        return (signSciNot < 0) ? sign * val / power / stuff : sign * val / power * stuff;
    }

    return sign * val / power;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar( )) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i ;
}
