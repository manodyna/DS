// #include"struct.h"
// #include<stddef.h>

void deleteFront(NODE **first)
{
    // creating a pointer temp and making it point to the first node
    NODE *temp;
    temp = *first;
    // checking for empty list, nothing to delete
    if (first == NULL)
    {
        printf("empty list");
    }
    else
    // reassigning the pointer pointing to the first node to point to the next node and freeing the memory occupied by the first node by assigning it to temp and freeing temp
    {
        *first = (*first)->link;
        free(temp);
    }
}

void deleteRear(NODE **first)
{
    NODE *temp;
    NODE *prev;
    prev = getNode();
    temp = *first;
    prev = *first;
    if (first == NULL)
    {
        printf("empty list");
    }
    else
    {
        // iterate through the list to get the last element, make elem->link=NULL free the last node while storing it in temp
        // check if the last element is null while not reaching it else you lose the prev element
        while (temp->link->link != NULL)
        {
            // reaches only the second last element
            temp = temp->link;
        }
        // assign prev to a temp variable, now go to the last element, make prev->link=null marking the end of the list
        // free the stray node temp without any consequences :-)
        prev = temp;
        temp = temp->link;
        prev->link = NULL;
        free(temp);
    }
}

void deleteAtPos(NODE **first, int pos)
{
    NODE *temp;
    NODE *prev;
    prev = getNode();
    temp = *first;
    prev = *first;
    if (first == NULL)
    {
        printf("empty list");
    }
    else
    {
        int count = 1;
        // iterate through the list to≈ get the last element, make elem->link=NULL free the last node while storing it in temp
        // check if the last element is null while not reaching it else you lose the prev element
        while (temp->link->link != NULL)
        {
            // reaches only the second last element
            temp = temp->link;
            if (count == pos-1)
            {
                break;
            }

            ++count;
        }
        // assign prev to a temp variable, now go to the last element, make prev->link=prev->link->link making it point to the element immediately after the one to be deleted
        // free the stray node temp without any consequences :-)
        prev = temp;
        temp = temp->link;
        prev->link = prev->link->link;
        free(temp);
    }
}