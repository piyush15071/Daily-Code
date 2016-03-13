#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root;

void insert(int data);
void search(int data);
void postorder(struct node* pointer);

void insert(int data)
{
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->right=NULL;
        root->left=NULL;
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
                temp->data=data;
                temp->right=temp->left=NULL;
                pointer->right=temp;
                break;
            }
            if(pointer->left==NULL && pointer->data>data)
            {
                struct node* temp;
                temp=(struct node*)malloc(sizeof(struct node));
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

void postorder(struct node *pointer)
{
    if (root == NULL)
    {
        printf("No elements in the tree to display ");
        return;
    }
    if (pointer->left != NULL)
        postorder(pointer->left);
    if (pointer->right != NULL)
        postorder(pointer->right);
    printf("%d ", pointer->data);
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
        postorder(root);
        printf("\n");
        i++;
    }
    return 0;
}
