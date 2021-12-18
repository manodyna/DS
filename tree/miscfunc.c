tree *getnode()
{
    tree *temp;
    temp = (tree *)malloc(sizeof(tree));
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

void search(int data, tree *root)
{
    if (root == NULL)
    {
        printf("element not found\n");
        return;
    }
    else if (data == root->data)
    {
        printf("element found\n");
        return;
    }
    else if (data < root->data)
    {
        search(data, root->left);
    }
    else if (data > root->data)
    {
        search(data, root->right);
    }
}

