// #include "struct.h"
void insertFront(int d, NODE **head)
{
    NODE *temp;
    temp = getNode();
    temp->data = d;
    NODE *last;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        last = (*head)->prev;
        temp->next = *head;
        // (*head)->prev->next=temp;
        (*head)->prev = temp;
        last->next = temp;
        temp->prev = last;
        // (*head)->prev = temp;
        *head = temp;
    }
}
void insertRear(int d, NODE **head)
{
    NODE *last;
    NODE *temp;
    temp = getNode();
    temp->data = d;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        last=(*head)->prev;
        last->next=temp;
        temp->prev=last;
        (*head)->prev=temp;
        temp->next=*head;
        *head=temp;
    }
}