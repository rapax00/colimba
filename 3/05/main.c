/* Exercise 3-5. /Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob ( n , s , 16 ) formats n as a hexadecimal integer in s. */

#include <stdio.h>

#define MAX 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int number = 50, base = 8;
    char str[MAX];

    itob(nro, str, base);

    int i;
    for (i = 0; '\0' != str[i]; i++) {
        printf("%c", str[i]);
    }
}

void itob(int n, char s[], int b) {
    int resto, i = 0;

    if (16 == b) {                              /* dec to hex */
        do {
            resto = n % b;
            if (resto <= 9) {
                s[i] = resto + '0';
            } else {
                s[i] = resto - 10 + 'A';
            }
            i++;
        } while ((n = n / b) > 0);
    } else if (b <= 9) {                        /* dec to other  base < 9*/
        do {
            s[i] = n % b + '0';
            i++;
        } while ((n = n / b) > 0);
    }

    s[i] = '\0';

    reverse(s);
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

/* TODO: make converter to base > 9 */
