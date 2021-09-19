void deleteFront(NODE **first)
{
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        NODE *temp;
        // the temp node points to the ADDRESS of first not its value
        temp = *first;
        *first = (*first)->next;
        (*first)->prev = NULL;
        // DO NOT free first to avoid losing access to the list
        // DO NOT free temp untill the first node points to null on the left hand side
        free(temp);
    }
}
void deleteRear(NODE **first)
{
    if (first == NULL)
    {
        printf("empty list\n");
    }else
    {
        NODE* temp;
        NODE* current;
        // the temp node points to the ADDRESS of first not its value
        current=*first;
        while (current->next!=NULL)
        {
            current=current->next;
        }
        // current now is at the last node
        temp=current;
        // make current the second last node
        current=current->prev;
        current->next=NULL;
        // isolate and free temp
        free(temp);
    }
    
}
void deleteAtPos(NODE **first, int pos)
{
    if (pos==1)
    {
        deleteFront(first);
    }else
    {
        NODE* temp;
        NODE* current;
        // the temp node points to the ADDRESS of first not its value
        current=*first;
        int count=0;
        while (current->next!=NULL)
        {
            current=current->next;
            ++count;
            if (count==pos)
            {
                temp=current;
                current=current->prev;
                current->next=current->next->next;
                free(temp);
            }
            
        }
    }
    
    
}