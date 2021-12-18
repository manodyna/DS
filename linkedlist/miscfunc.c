//  #include"struct.h"
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

    prev = NULL;
    curr = *first;

    while (curr != NULL)
    {
        temp = curr->link;
        curr->link = prev;
        prev = curr;
        curr = temp;
    }
    *first = prev;
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

// reverse, is palindrome on sll, remove duplicates from sorted ll, delete alternate nodes of dll

int count(NODE *first, int ele)
{
    NODE *temp;
    NODE *cur;
    int count = 0;
    temp = first;
    int data;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            count++;
        }
        temp = temp->link;
    }
    return count;
}

int isPalindrome(NODE *first)
{
    NODE *temp;
    NODE *cur;
    NODE *counter;
    counter=first;
    cur = temp = first;
    int length = 0;
    int d1, d2;
    int count = 0;
    while (counter->link != NULL)
    {
        counter = counter->link;
        length++;
    }
    // length++;

    while (cur != NULL)
    {
        d1 = cur->data;
        for (int i = 0; i < length - count; i++)
        {
            temp = temp->link;
        }
        d2 = temp->data;
        temp=first;
        if (d1 != d2)
        {
            return 0;
        }
        cur=cur->link;
    }
    return 1;
}
