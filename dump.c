#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *llink, *rlink;
    int rthread, lthread;
}node;

struct tree{
    node *root;
};

typedef struct tree tree;

node *initialize(){
    tree *new=malloc(sizeof(tree));
    new->root=NULL;
    return (new);
}

void insert(tree *root, int ele){
    node *temp = malloc(sizeof(node));
    if(temp==NULL){
        return;
    }else{
        temp->data=ele;
        temp->rlink=temp->llink=NULL;
        temp->rthread=temp->lthread=1;
        node *cur=root;
        if(cur==NULL){
            tree->root->root=temp;
            return;
        }
        while(1){
            if(ele<cur->data){
                if(cur->lthread==0){
                    cur=cur->llink;
                }
                    else{
                    break;
                }
            }

            else if(ele>cur->data){
                if(cur->rthread==0){
                    cur=cur->rlink;
                }
                else{
                    break;
                }
            }
        }

        if(ele<cur->data){
            temp->llink=cur->llink;
            temp->rlink=cur;
            cur->lthread=0;
            cur->llink=temp;

        }   
        else{
            temp->rlink=cur->rlink;
            temp->llink=cur;
            cur->rlink=temp;
            cur->rthread=0;
        }

    }
}

node* inorder(node *root){
    if(root==NULL){
        printf("empty\n");
        return;
    }else if(root->lthread=1){
        
    }
}

int main(){
    int choice, data;
    tree *root=initialize();
    while(1){
        printf("insert exit exit\n");
        prinf("enter",&choice);
        switch(choice){
            case 1:
            printf("data\n");
            scanf("%d", &data);
            inorder(root);
        }
    }
}