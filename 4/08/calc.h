#ifndef CALC_INCLUDED
#define CALC_INCLUDED

#define MAXOP 100
#define NUMBER '0'              /* signal that a number was found */

enum {TOP = '1', SWP, CLR, SIN, EXP, POW, ERR};

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void ungets(char s[]);

#endif // CALC_INCLUDED
