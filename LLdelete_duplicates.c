#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct node* construct_LL(int arr[],int size)
{
    struct node* head = newNode(arr[0]);
    struct node* temp = head;
    for(int i=1;i<size;i++)
    {
        temp->next = newNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void print_LL(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_duplicates(struct node* head)
{
    struct node* temp= head;
    while(temp!=NULL)
    {
        struct node* temp2=temp;
        while(temp2->next!=NULL)
        {
            if(temp2->next->data==temp->data)
            {
                temp2->next=temp2->next->next;

            }
            else
            {
                temp2=temp2->next;
            }
        }
        temp=temp->next;
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct node* head = construct_LL(arr,size);
    print_LL(head);
    delete_duplicates(head);
    print_LL(head);
    return 0;
}