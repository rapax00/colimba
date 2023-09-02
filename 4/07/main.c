/* Exercise 4-7. Write a routine ungets ( s ) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch? */

#include <stdio.h>
#include <stdlib.h>             /* for atof() */
#include <math.h>
#include "calc.h"

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
            if (0.0 != elem) {
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
        case CLR:
            while(pop() != 0.0) {
                ;
            }
            printf("Command action: clear stack succefull.\n");
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            double y = pop();
            double x = pop();
            if (0 == x && y <= 0) {
                printf("error: zero exp %.8g\n", y);
            } else if (x < 0) {
                printf("note: %.8g convert to int. %.8g \n", y, x);
                push(pow(x, (int)y));   /* NOTE: I don't know why its not result in a negative number */
            } else {
                push(pow(x, y));
            }
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
