#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct stack
{
    int data;
    int top;
    struct stack *link;
};
typedef struct stack stack;

int isEmpty(stack **s)
{
    if (*s == NULL)
    {
        return (-1);
    }
    return -1;
}

stack *getNode()
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    temp->link = NULL;
    return temp;
}

void push(int ele, stack **s)
{
    stack *temp;
    temp = getNode();
    if (*s == NULL)
    {
        *s = temp;
    }
    else
    {
        temp->link = (*s)->top;
        (*s)->top = temp;
    }
}

int pop(stack *s)
{
    if (s == NULL)
    {
        printf("stack overflow\n");
        return(-1);
    }
    else
    {
        stack *temp;
        temp = getNode();
        temp=s->top;

        temp->link = s->link->link;
        s = temp;
        free(s);
        return(1);
    }
}

int main()
{
    stack **s;
    // s.top = -1;
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
            push(ele, s);
            break;
        case 2:
            x = pop(*s);
            if (x == -1)
            {
                printf("underflow condition\n");
            }
            else
            {
                printf("%d is deleted\n", x);
            }
            break;
        // case 3:
        //     x = peep(&s);
        //     printf("%d is on the top of stack\n", x);
        //     break;
        // case 4:
        //     display(s);
        //     break;
        default:
            exit(0);
            break;
        }
    }
}