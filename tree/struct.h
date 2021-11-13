struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node tree;

tree *getnode();
tree *insert(int data, tree *root);
void preOrder(tree *root);
void postOrder(tree *root);
void inOrder(tree *root);
tree *delete(int data, tree *root);