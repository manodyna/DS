#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node
{
    char data;
    struct node *rlink;
    struct node *llink;
};

typedef struct node node;

node *getNode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    return temp;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->llink);
        printf("%c", root->data);
        inorder(root->llink);
    }
}

node *create(char *postfix)
{
    node *temp;
    temp = getNode();
    node **s;
    s = malloc(sizeof(node *) * 100);
    int top = 0;
    char symbol;
    for (int i = 0; (symbol = (postfix[i]) != '\0'); i++)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else
        {
            temp->data = symbol;
            temp->rlink = temp->llink = NULL;
        }
        if (isalnum(symbol))
        {
            s[top++] = temp;
        }
        else
        {
            temp->rlink = s[--top];
            temp->llink = s[--top];
            s[top++] = temp;
        }
    }
    return (s[--top]);
}

float eval(node *root)
{
    float num;
    switch (root->data)
    {
    case '+':
        return (eval((root->rlink)) + eval((root->llink)));
        break;
    case '-':
        return (eval(root->rlink) - eval(root->llink));
        break;
    case '*':
        return (eval(root->rlink) * eval(root->llink));
        break;
    case '/':
        return(eval(root->rlink)/eval(root->llink));
        break;
    case '$':
    case '^':
        return(pow(eval(root->rlink),eval(root->llink)));
    default:
        if(isalpha(root->data)){
            return(-999);
        }else{
            return(root->data + '0' + '+' + '0') ;
        }
        break;
    }

}

int main()
{
    node *root = NULL;
    char *ex;
    scanf("%s", ex);
    root = create(ex);
    // inorder(root);
    printf("%f", eval(root));
}