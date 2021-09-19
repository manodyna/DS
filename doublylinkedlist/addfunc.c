// #include "struct.h"
void insertFront(int d, NODE **first)
{
    NODE *temp;
    temp = getNode();
    temp->data = d;
    temp->next = temp->prev = NULL;
    // check if first pointer is a null pointer as it implies an empty list
    if (*first == NULL)
    {
        // if empty set address of first=temp
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
    NODE *temp;
    temp = getNode();
    NODE *current;
    current = *first;
    temp->data = d;
    temp->next = temp->prev = NULL;
    if (*first == NULL)
    {
        *first = temp;
    }
    else
    {
        // iterate to the end of list while the current node does not point to null
        while (current->next != NULL)
        {
            current = current->next;
        }
        // link the nodes
        current->next = temp;
        temp->prev = current;
    }
}

void insertPos(int d, int pos, NODE **first)
{
    NODE *temp;
    temp = getNode();
    NODE *current;
    current = *first;
    temp->data = d;
    temp->next = temp->prev = NULL;
    int count=1;
    if (pos==1)
    {
        insertFront(d, first);
    }else
    {
        // iterating to the node just before insertion position
        while (count<pos-1)
        {
            count++;
            current=current->next;
        }
        // linking the new node
        temp->next=current->next;
        // go to the node after current and link temp as it's next node
        current->next->prev=temp;
        // current->next=temp;
        temp->prev=current;
        
    }
    
    
}
