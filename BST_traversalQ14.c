#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* construct_BST(int arr[],int size)
{

    struct node *root = newNode(arr[0]);
    for(int i=1;i<size;i++)
    {
        struct node * temp = root;
       while(1)
       {
        if(arr[i]<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=newNode(arr[i]);
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
        else
        {
            if(temp->right==NULL)
            {
                temp->right=newNode(arr[i]);
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
       }
    }

    return root;

}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}



int main()
{
    printf("Enter the number of elements in the array: ");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct node *root = construct_BST(arr,size);
    printf("Inorder traversal of the BST is: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal of the BST is: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal of the BST is: ");
    postorder(root);
    printf("\n");

    return 0;
}
