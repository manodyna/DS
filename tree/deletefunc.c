tree *delete (int ele, tree *root)
{
    tree *cur = root;
    tree *prev = NULL;
    while (cur != NULL && cur->data != ele)
    {
        prev = cur;
        if (ele < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (cur == NULL)
    {
        return (root);
    }
    if (cur == NULL)
    {
        printf("element not found\n");
    }
    else if (cur->left == NULL || cur->right == NULL)
    {
        tree *q;
        if (cur->left == NULL)
        {
            q = cur->left;
        }
        else
        {
            q = cur->left;
        }
        if (prev == NULL)
        {
            return q;
        }
        if (cur == prev->left)
        {
            prev->left = q;
        }
        else
        {
            prev->right = q;
        }
        free(q);
    }
    else
    {
        tree *p = NULL;
        tree *temp;
        temp = cur->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
        {
            p->left = temp->right;
        }
        else
        {
            cur->right = temp->right;
        }
        cur->data = temp->data;
        free(cur);
    }
    return (root);
}