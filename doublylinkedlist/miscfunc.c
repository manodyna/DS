
NODE *getNode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = 0;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void display(NODE *first)
{
    NODE *temp;
    temp = first;
    if (temp == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverseRead(NODE *first)
{
    NODE *temp;
    temp = first;
    if (temp == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
        }
        while (temp->prev != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

void deleteAlternate(NODE **first)
{
    NODE *temp;
    temp = (*first)->next;
    NODE *cur;
    cur = *first;
    while (temp!=NULL)
    {
        for (int i = 0; i < 1; i++)
        {
            cur=cur->next;
        }
        
        // temp->next=temp->next->next;
        // temp->next->prev=temp;
        free(cur);
        temp=temp->next;
    }
    
}