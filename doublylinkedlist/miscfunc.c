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
    }
}