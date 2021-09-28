#include "struct.h"
void deleteFront(NODE **head)
{
    NODE *last;
    NODE *temp;
    last = *head;
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else if ((*head)->link == *head)
    {
        free(head);
    }
    else
    {
        while (last->link != (*head))
        {
            last = last->link;
        }
        last->link = (*head)->link;
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}
void deleteRear(NODE **head)
{
    NODE *last;
    NODE *temp;
    last = *head;
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else if ((*head)->link == *head)
    {
        free(head);
    }
    else
    {
        while (last->link->link != (*head))
        {
            last = last->link;
        }
        temp = last->link;
        last->link = *head;
        free(temp);
    }
}
