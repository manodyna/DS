// #include "struct.h"
NODE *getNode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->link=temp;
    return temp;
}
void reverse(NODE **head)
{
}
void display(NODE *head)
{
    NODE *current;
    current = head;
    if (current == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        do
        {
            printf("%d\t", current->data);
            current = current->link;
        } while (current != head);
    }
}
