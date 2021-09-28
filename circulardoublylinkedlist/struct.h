struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;

NODE *getNode();
void insertFront(int d, NODE **head);
void insertRear(int d, NODE **head);
void deleteFront(NODE **head);
void deleteRear(NODE **head);
// void insertPos(int d, int pos, NODE **head);
// void reverse(NODE **head);
void display(NODE *head);
// void deleteAtPos(NODE **head, int pos);