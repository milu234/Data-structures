#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *newnode()
{
    struct node *node=(struct node *)malloc(sizeof(struct node));
    return(node);
};

void create()
{
    struct node *p,*q;
    int num;
    char choice;

    do
    {
        p=newnode();
        printf("\n Enter the data : ");
        scanf("%d",&num);

        p->data=num;
        p->left=NULL;
        p->right=NULL;

        if(root ==NULL)
        {
            root=p;
        }
        else
        {
            q=root;
            for(;;)
            {
                if(p->data<=q->data)
                {
                    if(q->left==NULL)
                    {
                        q->left=p;
                        break;
                    }
                    else
                    {
                        q=q->left;
                    }
                }

            else{

                    if(q->right==NULL)
                    {
                        q->right=p;
                        break;

                    }
                    else
                    {
                        q=q->right;
                    }
                }
            }
        }
        printf("\n Enter if you want to continue : ");
        scanf("%s",&choice);
    }while(choice=='y' ||choice=='Y');



}

void display(struct node *x,int i)
{
    int j;
    if(x==NULL)
    {
        return;
    }
    display(x->right,i+1);
    for(j=1;j<i;j++)
    {
        printf("\t");
    }
    printf("%d",x->data);
    printf("\n\n");
    display(x->left,i+1);
}
void search(struct node *x,int num)
{
    if(x==NULL)
    {
        printf("\n Data NOt found!!");
        return;
    }
    if(x->data==num)
    {
        return x;
    }
    if(num<=root->data)
    {
        if(x->left==NULL)
        {
            return;
        }
        else
        {
            return search(x->left,num);
        }
    }
    else
    {
        if(x->right==NULL)
        {
            return;
        }
        else
        {
            return search(x->right,num);
        }
    }
}
struct node *parent(struct node *p)
{
    struct node *q;
    if(p==root)
        return NULL;
    q=root;
    while(q!=NULL)
    {
        if(q->left==p||q->right==p)
            return q;
        if(p->data<=q->data)
            q=q->left;
        else
            q=q->right;
    }
    return q;
};

int isLeft(struct node *p)
{
    struct node *q;
    q=parent(p);
    if(q==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

struct node *findmax(struct node *p)
{
    if(p==NULL)
    {
        return p;
    }
    if(p->right==NULL)
    {
        return p;
        return findmax(p->right);
    }
    return p->data;

};

int delete_node(struct node *t,int num)
{
    struct node *p;
    if(root==NULL)
    {
        printf("\n The Tree is Empty!!!");
        return 0;
    }

    p=t;
    while(p!=NULL && p->data!=num)
    {
        if(num<p->data)
            p=p->left;
        else
            p=p->right;
    }

    if(p==NULL)
    {
        printf("\n Element not found!!1");
        return 0;
    }
    if(p->left==NULL&&p->right==NULL)
    {
        if(parent(p)==NULL)
        {
            root=NULL;
            return 1;
        }
        if(isLeft(p))
        {
            parent(p)->left=NULL;
            p=NULL;
            free(p);
            return 1;

        }
        else
        {
            parent(p)->right=NULL;
            p=NULL;
            free(p);
            return 1;
        }
    }

    else if(p->left!=NULL)
    {
        int val;
        struct node *ptr;

        ptr=findmax(p->left);
        val=ptr->data;
        delete_node(p,ptr->data);
        p->data=val;
        return 1;
    }
    else if(p==root)
    {
        root->right;
        free(p);
    }
    else
    {
        if(isLeft(p))
        {
            parent(p)->left=parent(p)->right;

        }
        else
        {
            parent(p)->right=parent(p)->right;
        }
    }
    return 1;

}
   /* if(p==NULL)
        return NULL;
    else if(num<p->data)
        p->left=delete_node(p->left,num);
    else if(num>p->right)
    p->right=delete_node(p->right,num);
    else
    {
        //case 1 No Child
        if(p->left==NULL && p->right==NULL)
        {
            free(p);
            p=NULL;

        }
        else if(p->left==NULL)
        {
            struct node *temp=p;
            p=p->right;
            free(temp);

        }
        else if(p->right==NULL)
        {
            struct node *temp=p;
            p=p->left;
            free(temp);

        }
        else
        {
            //case 3 two children
            struct node *temp=findmax(p->left);
            p->data=temp->data;
            p->left=delete_node(p->left,temp->data);
        }
    }
        return p;*/

void main()
{
    int n;
    create();
    display(root,0);

    printf("enter data to be deleted : ");
            scanf("%d",&n);
            int flag=0;
            flag=delete_node(root,n);
            if(flag==1)
            {
                printf("\n Element deleted !!\n");
                display(root,0);
            }
            else if(flag==0)
            {
                printf("\n Element not found");
            }




}
