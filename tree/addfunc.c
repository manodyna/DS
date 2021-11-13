tree *insert(int data, tree *root)
{
    tree *temp = getnode();
    temp->data = data;
    tree *prev = NULL;
    if (root == NULL)
    {
        root = temp;
        return (root);
    }
    else
    {
        tree *cur = root;
        while (cur != NULL)
        {
            prev = cur;
            if (data < cur->data)
            {
                cur = cur->left;
            }
            else if (data > cur->data)
            {
                cur = cur->right;
            }
            else
            {
                printf("no duplicates allowed\n");
                return(0);
            }
        }
    }
    if (temp->data < prev->data)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
    return(root);
}