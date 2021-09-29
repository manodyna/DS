#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top;
    int capacity;
    char *arr;
};

typedef struct stack stack;

int isEmpty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(char ele, char *s, int *top)
{
    (*top)++;
    s[*top] = ele;
}

char pop(char *s, int *top)
{
    char c = (s[*top]);
    (*top)--;
    return c;
}

int match(char *s)
{
    char a, ch, stack[20];
    int top, i;
    top = -1;
    while (s[i] != '\0')
    {
        ch = s[i];
        switch (ch)
        {
        case '(':
            push(ch, stack, &top);
            break;

        case '[':
            push(ch, stack, &top);
            break;

        case '{':
            push(ch, stack, &top);
            break;

        case ')':
            if (isEmpty(top) != 1)
            {
                a = pop(stack, &top);
                if (a == '(')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;
        case '}':
            if (isEmpty(top) != 1)
            {
                a = pop(stack, &top);
                if (a == '{')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;

        case ']':
            if (isEmpty(top) != 1)
            {
                a = pop(stack, &top);
                if (a == '[')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;
        }
        i++;
    }
    if (isEmpty(top))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // int top = -1;
    int res;
    char string[500];
    printf("enter the string\n");
    scanf("%s", string);
    res = match(string);
    if (!res)
    {
        printf("match");
    }
    else
    {
        printf("!match");
    }
}
