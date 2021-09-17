// #include"struct.h"
// #include<stddef.h>

NODE *getNode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = 0;
    temp->link = NULL;
    return temp;
}
void reverse(NODE **first)
{
    NODE *curr, *prev, *temp;

      prev=NULL;
      curr=*first;

      while(curr!=NULL)
      {
       temp=curr->link;
       curr->link=prev;
       prev=curr;
       curr=temp;
      }
      *first=prev;

}
void display(NODE *first)
{
    NODE *temp = getNode();
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
            temp = temp->link;
        }
        printf("\n");
    }
}