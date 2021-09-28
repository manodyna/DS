void deleteFront(NODE **head)
{
    if (*head == NULL)
    {
        printf("empty list\n");
    }
    else if ((*head)->next == *head)
    {
        free(*head);
    }
    else
    {
        NODE *temp;
        temp = getNode();
        temp = (*head)->next;
        NODE *first;
        first = (*head)->next->next;
        first->prev = (*head);
        (*head)->next = first;
        free(temp);
    }
}
void deleteRear(NODE **head)
{
    if (*head == NULL)
    {
        printf("empty list\n");
    }
    else if ((*head)->next == *head)
    {
        free(*head);
    }
    else
    {
        NODE *temp;
        temp = getNode();
        temp = (*head)->prev;
        (*head)->prev = (*head)->prev->prev;
        (*head)->prev->next = (*head);
        free(temp);
    }
}
