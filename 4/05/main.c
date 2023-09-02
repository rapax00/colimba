/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See
<math. h> in Appendix B, Section 4. */

#include <stdio.h>
#include <stdlib.h>             /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP 100

/* reverse Polish Calculator */
int main(void) {
    int type;
    double op, op2;
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
            op = pop();
            if(op) {
                printf("Command action: top element is: %.8g\n", op);
                push(op);
            }
            break;
        case SWP:
            op2 = pop();
            op = pop();
            push(op2);
            push(op);
            printf("Command action: swap succefull. Now top is %.8g, and its predecessor is %.8g\n", op, op2);
            break;
        case DUP:
            op = pop();
            push(op*2);
            printf("%.8g duplicated. -> %.8g\n", op, op*2);
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
            op2 = pop();
            op = pop();
            if (0 == op && op2 <= 0) {
                printf("error: zero exp %.8g\n", op2);
            } else if (op < 0) {
                printf("note: %.8g convert to int. -> %d \n", op2, (int)op2);
                push(pow(op, (int)op2));   /* NOTE: I don't know why its not result in a negative number */
            } else {
                push(pow(op, op2));
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
