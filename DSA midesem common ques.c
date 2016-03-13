#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int color;
    struct node* right;
    struct node* left;
    struct node* prev;
};

struct node* root;

void insert(int data);


void insert(int data)
{
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->color=0;
        root->data=data;
        root->right=NULL;
        root->left=NULL;
        root->prev=NULL;
    }
    else
    {
        struct node* pointer;
        pointer=root;
        while(1)
        {
            if(pointer->right==NULL && pointer->data<data)
            {
                struct node* temp;
                temp=(struct node*)malloc(sizeof(struct node));
                temp->prev=pointer;
                temp->color=0;
                temp->data=data;
                temp->right=temp->left=NULL;
                pointer->right=temp;
                break;
            }
            if(pointer->left==NULL && pointer->data>data)
            {
                struct node* temp;
                temp=(struct node*)malloc(sizeof(struct node));
                temp->prev=pointer;
                temp->color=0;
                temp->data=data;
                temp->right=temp->left=NULL;
                pointer->left=temp;
                break;
            }
            if(pointer->data<data && pointer->right!=NULL)
                pointer=pointer->right;
            if(pointer->data>data && pointer->left!=NULL)
                pointer=pointer->left;
        }
    }
}

int depth(struct node* pointer)
{
    if (pointer==NULL)
        return 0;
    if (pointer->left==NULL && pointer->right==NULL)
       return 1;
    if (pointer->left==NULL)
       return depth(pointer->right)+1;
    if (pointer->right==NULL)
       return depth(pointer->left)+1;

    int p,q;
    p=depth(pointer->left);
    q=depth(pointer->right);
    if(p<=q)
        return (p+1);
    if(p>q)
        return (q+1);
}

void lca(int a, int b)
{
        struct node* pointer;
        struct node* pointer1;
        pointer=root;
        while(1)
        {
            if(pointer->data>a)
                pointer=pointer->left;
            if(pointer->data<a)
                pointer=pointer->right;
            if(pointer->data==a)
                break;
        }
        pointer1=pointer;
        pointer1->color=1;
        while(pointer1->prev!=NULL)
        {
            pointer1=pointer1->prev;
            pointer1->color=1;
        }
        pointer1=root;
        while(1)
        {
            if(pointer1->data>b)
                pointer1=pointer1->left;
            if(pointer1->data<b)
                pointer1=pointer1->right;
            if(pointer1->data==b)
                break;
        }
        while(pointer1->color!=1)
            pointer1=pointer1->prev;
        pointer->color=0;
        while(pointer->prev!=NULL)
        {
            pointer=pointer->prev;
            pointer->color=0;
        }
        printf("%d\n",pointer1->data);

}

int main()
{
    int t,i=0;
    scanf("%d",&t);
    while(i!=t)
    {
        int n,j;
        scanf("%d",&n);
        int arr[n+1];
        root=NULL;
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            insert(arr[j]);
        }
        int mindep;
        mindep=depth(root);
        printf("%d\n",mindep);
        int q;
        scanf("%d",&q);
        int k=0;
        while(k!=q)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            lca(a,b);
            k++;
        }
        i++;
    }
    return 0;
}
