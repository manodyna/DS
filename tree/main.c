#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "addfunc.c"
#include "deletefunc.c"
#include "miscfunc.c"
#include "displayfunc.c"

int main()
{
    int ele, x;
    int choice;
    tree *root = NULL;
    while (1)
    {
        printf("1.create a binary search tree\n2.preorder\n3.inorder\n4.postorder\n5.delete\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("enter the data\n");
            scanf("%d", &ele);
            root = insert(ele, root);
            break;
        case 2:
            preOrder(root);
            printf("\n");
            break;
        case 3:
            inOrder(root);
            printf("\n");
            break;
        case 4:
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("enter the node to be deleted\n");
            scanf("%d", &ele);
            root = delete (ele, root);
            break;
        case 6:
            printf("enter the data\n");
            scanf("%d", &ele);
            search(ele, root);
        }
    }
}