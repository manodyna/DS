//Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
struct BST
{
    int data;
    struct BST *rlink;
    struct BST *llink;
};
typedef struct BST bin;
bin *getnode(int data)
{
    bin *temp = (bin *)malloc(sizeof(bin));
    if (temp == NULL)
    {
        printf("No enough space in heap");
        return (NULL);
    }
    else
    {
        temp->data = data;
        temp->rlink = temp->llink = NULL;
        return temp;
    }
}
void inorder(bin *root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("\t%d\n", root->data);
    inorder(root->rlink);
}
bin *create(char *postfix)
{
    bin *temp;
    bin **s;
    s = malloc(sizeof(bin) * 100);
    int top = 0;
    char symbol;
    int i;
    for (i = 0; (symbol = postfix[i]) != '\0'; i++)
    {
        temp = malloc(sizeof(bin));

        if (temp == NULL)
            return (NULL);
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
float eval(bin *root)
{
    float num;
    switch (root->data)
    {
    case '+':
        return (eval(root->rlink) + eval(root->llink));
        break;

    case '-':
        return (eval(root->rlink) - eval(root->llink));
        break;

    case '*':
        return (eval(root->rlink) * eval(root->llink));
        break;
    case '/':
        return (eval(root->rlink) / eval(root->llink));
        break;
    case '$':
    case '^':
        return (pow(eval(root->rlink), eval(root->llink)));
    default:
        if (isalpha(root->data))
        {
            printf("%c=", root->data);
            scanf("%f", &num);
            return (num);
        }
        else
            return (root->data - '0');
    }
}

int main()
{
    int ele;
    int choice;
    bin *root = NULL;
    char *postfix;
    printf("enter the postfix expression\n");
    scanf("%s", postfix);
    root = create(postfix);
    printf("%f", eval(root));
}