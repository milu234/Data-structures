#include<stdio.h>
#include<process.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *node =(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return(node);
}

void preorder(struct node *node)
{
    if(node==NULL)
        return;
    printf("\t %d",node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct node *node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("\t%d",node->data);
}

void inorder(struct node *node)
{
    if(node == NULL)
        return;
    inorder(node->left);
    printf("\t%d",node->data);
    inorder(node->right);
}


int main()
{
     struct node *root  = newnode(1);
     root->left = newnode(2);
     root->right = newnode(3);
     root->right->left = newnode(8);
     root->right->right = newnode(9);
     root->left->left = newnode(4);
     root->left->right = newnode(5);
     root->left->left->left = newnode(6);
     root->left->left->right = newnode(7);

     printf("\nPreorder traversal of binary tree is \n");
     preorder(root);

     printf("\nInorder traversal of binary tree is \n");
     inorder(root);

     printf("\nPostorder traversal of binary tree is \n");
     postorder(root);

     getchar();
     return 0;
}

