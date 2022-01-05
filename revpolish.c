/*Reverse Polish Evaluator */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100 /*max size of the operand/operator */

int getop(char []);
void push(double x);
double pop(void);

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));       /* "1234.567" => 1234.567 */
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
            push(pop()/op2);
            break;
        case '\n':
            printf("\nResult = %lf", pop());
            break;
        default:
            printf("\nError: Incorrect input provide.");
            return(-1);
        }
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double stack[MAXVAL];

/* push */
void push(double val) {
    if(sp < MAXVAL)
        stack[sp++] = val;
    else
        printf("\nStack Overflow.");
}

/* pop */
double pop(void) {
    if(sp == 0) {
        printf("\nStack Underflow.");
        return 0.0;
    } else {
        return stack[--sp];
    }
}

int getch(void);
void ungetch(int);

/* To find the next operator or operand */
int getop(char s[]) {
    int i, c;

    /*          200.123 500.678 + 4 5+ * */
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))

    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
#define BUFSIZE 100

char buf[BUFSIZE]; /*for ungetch() */
int bufp = 0;       /* next free position in buf */

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*pushing the character into the buffer */
{
    if(bufp >= BUFSIZE)
        printf("\nBuffer overflow");
    else
        buf[bufp++] = c;
}
