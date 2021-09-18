// #include "struct.h"
void insertFront(int d, NODE **first)
{
    NODE *temp;
    temp = getNode();
    temp->data = d;
    temp->next = temp->prev = NULL;
    if (*first == NULL)
    {
        *first = temp;
    }
    else
    {
        temp->next = *first;
        (*first)->prev = temp;
        *first = temp;
    }
}

void insertRear(int d, NODE **first)
{
}

void insertPos(int d, int pos, NODE **first)
{
}
