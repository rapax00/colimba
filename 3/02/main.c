/* Exercise 3-2. Write a function escape(s,t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters. */

#include <stdio.h>

#define LENGHT 10

void escape(char s[], char t[]);
void visualToReal(char s[], int lenght);

/* Test */
int main() {
    char s[LENGHT];
    char t[LENGHT] = {'a', '\t', 'b', '\n', '\t', 's', '\n', ' ', 'b', '\0'};
    int i;

    printf("begining t\n");
    for (i = 0; i < LENGHT; ++i) {
        printf("%c", t[i]);
    }
    printf("\nend t\n");

    printf("\nprint of function escape ->");
    escape(s, t);

    printf("\n\nbegining final s\n");
    for (i = 0; i < LENGHT; ++i) {
        printf("%c", s[i]);
    }
    printf("\nend final s\n");

    printf("\nWrite the string with visible escapes to convert:\n");
    visualToReal(s, LENGHT);

    printf("\ns before function\n");
    for (i = 0; i < LENGHT; ++i) {
        printf("%c", s[i]);
    }

    return 0;
}

void escape(char s[], char t[]) {
    int i;

    i = 0;
    while ('\0' != t[i]) {
        switch (t[i]) {
        case '\n':
            putchar('\\');
            putchar('n');
            break;
        case '\t':
            putchar('\\');
            putchar('t');
            break;
        default:
            putchar(t[i]);
        }
        s[i] = t[i];
        ++i;
    }
}

void visualToReal(char s[], int lenght) {
    int c, old;

    int i = 0;
    while (((c = getchar()) != EOF) && i < lenght) {
        if (c == '\\') {
            old = c;
        } else if (('t' == c || 'n' == c) && old == '\\') {
            switch (c) {
            case 't':
                s[i-1] = '\t';
                --i;
                break;
            case 'n':
                s[i-1] = '\n';
                --i;
                break;
            }
            old = 0;
        } else {
            s[i] = c;
        }
        ++i;
    }
}

/* NOTE: I'm not a sure if this is the correct and more eficient way, but this is
that  I understood. */
