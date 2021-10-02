// #include"struct.h"
// #include<stddef.h>

// double pointer on first because the value of the element has to be modified while the pointer location remains constant
void insertFront(int d, NODE **first)
{
    NODE *temp = getNode();
    temp->data = d;
    if (*first == NULL)
    {
        // *first because the location of first should change to the location of temp
        *first = temp;
    }
    else
    {
        // *first to pass the address
        temp->link = *first;
        *first = temp;
    }
}

// double pointer on first because the value of the element has to be modified while the pointer location remains constant
void insertRear(int d, NODE **first)
{
    // get a temp node to insert the data, make temp->link=NULL as temp is the last node
    // get another temp var to keep track of the current node, DO NOT modify first, else you lose the entry point to the linked list
    NODE *temp = getNode();
    temp->data = d;
    NODE *current = *first;
    // iterating through the list to find the last node
    // current==NULL and not current->link==null as current is not initialiazed or given any memory space yet, so doues not have either a data or a link
    if (current == NULL)
    {
        *first = temp;
    }
    else
    {
        // current now is assigned and has data and link can be iterated through
        // current points to the adress of the first node which is now added
        while (current->link != NULL)
        {
            current = current->link;
        }
        // linking the last node to the temp node
        current->link = temp;
    }
}

void insertPos(int d, int pos, NODE **first)
{
    // get a temp node to insert the data, make temp->link=NULL as temp is the last node
    // get another temp var to keep track of the current node, DO NOT modify first, else you lose the entry point to the linked list
    NODE *temp = getNode();
    temp->data = d;
    NODE *current = *first;
    if (pos == 1)
    {
        // calling the insert at front function to isert at front if the pos==1
        insertFront(d, first);
    }
    // check for empty list, there are no positions in an empty list!!
    else if (current == NULL)
    {
        printf("empty list, do something!!! :-(");
    }
    else
    {
        int count = 1;
        while (current != NULL)
        {
            current = current->link;
            // using a count variable to break at the position specified as a stand in for a for loop
            // A for loop could have been a cleaner choice??
            ++count;
            if (count == pos)
            {
                temp->link = current->link->link;
                current->link = temp;
                break;
            }
        }
    }
}
