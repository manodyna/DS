#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include "addfunc.c"
#include "deletefunc.c"
#include "miscfunc.c"

int main()
{
    NODE *first=NULL;
    int choice, d,c;
    printf("Enter your choice \n1) Insert data at front of the list\n2) Display the list\n");
    printf("3) Insert data at rear end\n4) Delete at front\n5) Delete at rear\n6) Insert at position\n7) Delete at position\n");
    printf("8) Delete at position\n9) Reverse the list\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the element\n");
            scanf("%d", &d);
            // &first because i have to pass the adress of the first node(&first) to the parameter expecting a pointer to a pointer so pass address of an address
            insertFront(d, &first);
            break;

        case 2:
            printf("The element in the list are: \t");
            // not &first because the value of the first node is expected by the pointer and there is no obligation to keep memory locations undisterbud while displaying
            // just ensure the pointer first points to the first node
            display(first);
            // printf(":-)\n");
            break;

        case 3:
            printf("Enter the element to be inserted\n");
            scanf("%d", &d);
            insertRear(d, &first);
            break;

        case 4:
            deleteFront(&first);
            break;

        case 5:
            deleteRear(&first);
            break;

        case 6:
            printf("enter the posistion and element\n");
            int pos;
            scanf("%d %d", &pos, &d);
            insertPos(pos, d, &first);
            break;

        // case 5:
        //     printf("Ordered Insertion\n Enter the element");
        //     scanf("%d", &d);
        //     insert_in_order(d, &first);
        //     break;

        case 7:
            printf("enter the posistion and element\n");
            // int pos;
            scanf("%d", &pos);
            deleteAtPos(&first, pos);
            break;

        case 8:
            reverse(&first);
            break;
        
        case 9:
            // int c;
            c=count(first, 3);
            printf("%d", c);
            break;

        case 10:
            c=isPalindrome(first);
            if (c==1)
            {
                printf("is palindrome");
            }else{
                printf("not palindrome");
            }
            

        default:
            printf("Invalid choice \n");
            exit(1);
            break;
        }
    }
    return (0);
}