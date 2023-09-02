/* Exercise 4-3. Given the basic framework, it's straightforward to extend the cal-
culator. Add the modulus (%) operator and provisions for negative numbers. */

#include <stdio.h>
#include <stdlib.h>             /* for atof() */
#include <ctype.h>

#define MAXOP 100               /* max size of operand of operator */
#define NUMBER '0'              /* signal that a number was found */
#define MAXVAL 100              /* maximum depth of val stack */
#define BUFSIZE 100

int sp = 0;                     /* next free stack position */
double val[MAXVAL];             /* val stack */
char buf[BUFSIZE];              /* buffer for ungetch */
int bufp = 0;                   /* next free position in buf */

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

/* reverse Polish Calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (0.0 != op2) {
                push(pop() / op2);
            } else {
                printf("error: zero division\n");
            }
            break;
        case '%':
            op2 = pop();
            if (0 != (int)op2) {
                push((int)pop() % (int)op2);
            } else {
                printf("error: zero modulus\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value form stack */
double pop(void) {
    if (0 < sp) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while (' ' == (s[0] = c = getch()) || '\t' == c) {
        ;
    }
    s[1] = '\0';


    if (!isdigit(c) && c != '.') {
        int aux = c;
        if (isdigit(c = getch())) {
            ungetch(c);
        } else {
            return aux;               /* not a number */
        }
    }

    i = 0;
    if (isdigit(c)) {           /* collect integer part */
        while (isdigit(s[++i] = (c = getch()))) {
            ;
        }
    }

    if ('.' == c) {             /* collect fraction part */
        while (isdigit(s[++i] = c = getch())){
            ;
        }
    }
    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void) {               /* get a (possibly pushed back) character */
    return (0 < bufp) ? buf[--bufp] : getchar();
}

void ungetch(int c) {           /* push character back on input */
    if (BUFSIZE <= bufp) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}
