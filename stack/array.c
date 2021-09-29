#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct stack
{
    int top;
    int st[3];
};
typedef struct stack stack;

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top == 2);
}

void push(int ele, stack *s)
{
    if (isFull(s))
    {
        printf("stack overflow\n");
    }
    else
    {
        s->top = (s->top) + 1;
        s->st[s->top] = ele;
    }
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        return (-1);
    }
    else
    {
        // decrement the top
        int x;
        (s->top)--;
        x=s->st[s->top];
        return (x);
    }
}

int peep(stack *s){
    if (isEmpty(s))
    {
        return (-1);
    }
    else
    {
        int x=s->st[s->top];
        return (x);
    }
}

void display(stack *s){
    if (isEmpty(s))
    {
        printf("empty stack\n");
    }else{
        for (int i = 0; i < 2; i++)
        {
            printf("%d\t", s->st[i]);
        }
        
    }
}

int main()
{
    stack s;
    s.top = -1;
    int option = 1, ele, choice;
    int i = 0, x;
    printf("1.push\n 2.pop\n 3.peep\n 4.display\n 5.exit\n");
    while (option)
    {

        printf("enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element\n");
            scanf("%d", &ele);
            push(ele, &s);
            break;
        case 2:
            x = pop(&s);
            if (x == -1)
            {
                printf("underflow condition\n");
            }
            else
            {
                printf("%d is deleted\n", x);
            }
            break;
        case 3:
            x = peep(&s);
            printf("%d is on the top of stack\n", x);
            break;
        case 4:
            display(&s);
            break;
        default:
            exit(0);
            break;
        }
    }
}