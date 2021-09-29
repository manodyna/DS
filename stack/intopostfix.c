#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct stack
{
    int top;
    char *arr;
};

typedef struct stack stack;

int getPrecedence(char ch)
{
    int prec;
    if (ch == '*' || ch == '/')
    {
        prec = 3;
    }
    else if (ch == '+' || ch == '-')
    {
        prec = 2;
    }
    else
    {
        prec = 1;
    }
    return prec;
}

void init(stack *s)
{
    s->top = -1;
}

void push(stack *s, char x)
{
    (s->top)++;
    s->arr[s->top] = x;
}

void init(stack *s){
    (s->top)--;
}

void pop(stack *s)
{
    char ch;
    ch = s->arr[s->top] - 1;
    return ch;
}

int top(stack *s){
    return (s->arr[s->top]);
}

void infixToPostfix(char *str)
{
    int *pos;
    *pos = 0;
    char ch;
    char post[100];
    int top = -1;

    while (str[*pos] != '\0')
    {
        char stack[50];
        ch = str[*pos];
        if (ch == 0 || ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5 || ch == 6 || ch == 7 || ch == 8 || ch == 9)
        {
            post[*pos] = ch;
        }
        else if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch, stack, &top);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (getPrecedence(ch) <= getPrecedence(peek(stack, pos)))
            {
                post[*pos] = pop(stack, pos);
            }
            push(ch, stack, pos);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            while (ch != '(' || ch != '[' || ch != '{')
            {
                post[*pos] = pop(stack, pos);
            }
        }
    }
    printf("%s", post);
}

int main()
{
    char str[100];
    char str2[100];
    printf("infix\n");
    scanf("%s", str);
    infixToPostfix(str);
}