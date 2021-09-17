#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


double compute(char sym, double o1, double o2)
{
    switch (sym)
    {
    case '+':
        return o1 + o2;
        // break;
    case '-':
        return o1 - o2;
        // break;
    case '*':
        return o1 * o2;
        // break;
    case '/':
        return o1 / o2;
        // break;
    case '^':
        return pow(o1, o2);
        // break;

    default:
        return 0;
    //     break;
    }
}

int main()
{
    double s[20];
    double result;
    double o2, o1;
    int top = -1;
    char postfix[20];
    char symbol;
    gets(postfix);
    for (int i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
        {
            // to get ascii of a number as type is a char
            s[++top] = symbol-'0';
        }
        else
        {
            o2 = s[top--];
            o1 = s[top--];
            result = compute(symbol, o1, o2);
            s[++top] = result;
        }
    }

    printf("%f", s[top--]);
}
