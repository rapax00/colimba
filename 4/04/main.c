/* Exercise 4-4. Add commands to print the top element of the stack without pop-
ping, to duplicate it, and to swap the top two elements. Add a command to
clear the stack. */

#include <stdio.h>
#include <stdlib.h>             /* for atof() */
#include "calc.h"

#define MAXOP 100

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
            if (0.0 != op2) {
                push((int)pop() % (int)op2);
            } else {
                printf("error: zero division\n");
            }
            break;
        case TOP:
            double elem = pop();
            if (0 < elem) {
                printf("Command action: top element is: %.8g\n", elem);
                push(elem);
            }
            break;
        case SWP:
            double top = pop();
            double preTop = pop();
            push(top);
            push(preTop);
            printf("Command action: swap succefull. Now top is %.8g, and its predecessor is %.8g\n", preTop, top);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case ERR:
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
