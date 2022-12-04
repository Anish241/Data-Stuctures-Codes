#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(char data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert_at_end(struct node* head,char data)
{
    struct node* temp;
    temp = create_node(data);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node* temp1;
        temp1 = head;
        while(temp1->right!=NULL)
        {
            temp1 = temp1->right;
        }
        temp1->right = temp;
        temp->left = temp1;
    }
    return head;
}

struct node* insert_at_position(struct node* head,char data,int pos)
{
    struct node* temp;
    temp = create_node(data);
    if(head==NULL)
    {
        head=temp;
    }

    else if(pos=1)
    {
        temp->right=head;
        head->left=temp;
        head=temp;
    }

    else
    {   struct node* temp2;
        for(int i=1;i<pos-1;i++)
        {
            temp2=temp2->right;
        }
        temp->left = temp2;
        temp->right = temp2->right;
        temp2->right->left = temp;
        temp2->right = temp;
    }
}

struct node* sortDLL(struct node* head)
{
    struct node* temp;
    temp = head;
    int i=0;
    while(temp->right!=NULL)
    {
        temp = temp->right;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        temp = head;
        for(int k=0;k<i-j-1;k++)
        {
            if(temp->data > temp->right->data)
            {
                int temp1;
                temp1 = temp->data;
                temp->data = temp->right->data;
                temp->right->data = temp1;
            }
            temp = temp->right;
        }
    }
    return head;
}

void printDLL(struct node* head)
{
    struct node* temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->right;
    }
}

int main()
{
    struct node* head;
    head = NULL;
    printf("Enter th choice: ");
    int choice;
    printf("\n1. Insert at end\n2. Insert at position\n3. Sort DLL\n4. Print DLL\n5. Exit\n");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
            {
                printf("Enter the data: ");
                int data;
                scanf("%d",&data);
                head = insert_at_end(head,data);
                break;
            }
            case 2:
            {
                printf("Enter the data: ");
                int data;
                scanf("%d",&data);
                printf("Enter the position: ");
                int pos;
                scanf("%d",&pos);
                head = insert_at_position(head,data,pos);
                break;
            }
            case 3:
            {
                head = sortDLL(head);
                break;
            }
            case 4:
            {
                printDLL(head);
                break;
            }
            default:
            {
                printf("Invalid choice");
            }
        }
        printf("\nEnter the choice: ");
        printf("\n1. Insert at end\n2. Insert at position\n3. Sort DLL\n4. Print DLL\n5. Exit\n");
        scanf("%d",&choice);
    }
}