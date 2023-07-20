/* Exercise 3-5. /Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob ( n , s , 16 ) formats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

#define MAX 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int number = 123, base = 13;
    char str[MAX];

    itob(number, str, base);

    int i;
    for (i = 0; '\0' != str[i]; i++) {
        printf("%c", str[i]);
    }
}

void itob(int n, char s[], int b) {
    int resto, i = 0;

    if (10 <= b || b <= 16) {                              /* dec to hex */
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
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* TODO: make converter to base > 9 */
