// #include "struct.h"
NODE *getNode()
{
    NODE *temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->next = temp->prev =temp;
    // temp->prev = temp->next;
    return (temp);
}
void display(NODE *head)
{
    NODE *temp;
    temp = head;
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
    printf("\n");
}