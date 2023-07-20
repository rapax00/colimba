/* Exercise 3-4. In a two's complement number representation, our version of
itoa does not handle the largest negative number, that is, the value of n equal
to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs. */

/* La version itoa no puede trabajar con el mayor numero negativo porque
en la linea cuando hace n = -n siendo n este numero no existe un espejo
del mayor numero negativo en los positivos, ya que este posible lugar es
ocupado por el 0 >:| */

/* Example itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {       /* record sign */
        n = -n;                 /* make n positive */
    }

    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s) ;
}

#include <stdio.h>

#define MAXNEG -2147483648
#define MAX 100

void itoa2(int n, char s[]);
void reverse(char s[]);

/* Test */
void main() {
    char s[MAX];

    itoa2(MAXNEG, s);

    printf("%s", s);

    return 0;
}


void itoa2(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {           /* record sign */
        n = -(n + 1);               /* sum one to n (in case if n is maxium negative, add this one in the last one if) and make n positive */
    }

    i = 0;
    do {                            /* generate digits in reverse order */
        s[i++] = n % 10 + '0';      /* get next digit */
    } while ((n /= 10) != 0);       /* delete it */

    if (sign < 0) {
        s[i++] = '-';
        s[0]++;                     /* add one to sum in first if */
    }
    s[i] = '\0';

    reverse(s) ;
}

void reverse(char s[]) {
    int i, j, k;

    for (i = 0; '\0' != s[i]; i++) {            /* count lenght of s */
        ;
    }

    char aux[i];

    for (j = 0; j < i; j++) {                   /* reverse s in aux */
        aux[j] = s[i - j - 1];
    }

    for (k = 0; k < i; k++) {                   /* copy aux to s */
        s[k] = aux[k];
    }

    s[k] = '\0';
}
