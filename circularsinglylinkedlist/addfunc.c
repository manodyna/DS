// #include "struct.h"
void insertFront(int d, NODE **head)
{
    NODE *temp;
    NODE *current;
    current = *head;
    temp = getNode();
    temp->data = d;
    if (*head == NULL)
    {
        *head = temp;
    }
    else if ((*head)->link == *head)
    {
        (*head)->link = temp;
        temp->link = *head;
        *head = temp;
    }
    else
    {
        temp->link = *head;
        while (current->link != *head)
        {
            current = current->link;
        }
        current->link = temp;
        *head = temp;
    }
}
void insertRear(int d, NODE **head)
{
    NODE *temp;
    NODE *current;
    current = *head;
    temp = getNode();
    temp->data = d;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->link = *head;
        while (current->link != *head)
        {
            current = current->link;
        }
        current->link = temp;
        temp->link = *head;
    }
}
