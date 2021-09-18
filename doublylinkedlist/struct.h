struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node NODE;

NODE* getNode();
void insertFront(int d, NODE **first);
void insertRear(int d, NODE **first);
void deleteFront(NODE **first);
void deleteRear(NODE **first);
void insertPos(int d, int pos, NODE **first);
void reverse(NODE **first);
void display(NODE *first);
void deleteAtPos(NODE **first, int pos);