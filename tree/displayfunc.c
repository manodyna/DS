// #include "struct.h"

void preOrder(tree *root)
{
    if (root==NULL)
    {
        return;
    }else{
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
       
}
void postOrder(tree *root)
{
    if(root==NULL){
        return;
    }else{
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}
void inOrder(tree *root)
{
    if (root==NULL)
    {
        return;
    }else{
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
    
}