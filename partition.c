#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create_Node(int data)
{
    struct node* new = (struct node*)(malloc(sizeof(struct node)));
    new->data=data;
    new->next=NULL;
    return new;
}

struct node* insert_at_end(struct node* head,int data)
{
    struct node* new = create_Node(data);
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        struct node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    return head;
}

struct node* partition(struct node* head, int x)
{
    struct node* smaller=NULL;
    struct node* larger = NULL;
    struct node* equal = NULL;
   

    struct node* temp = head;

    while(temp!=NULL)
    {
        if(temp->data<x)
        {
            smaller = insert_at_end(smaller,temp->data);
        }
        else if(temp->data==x)
        {
            equal = insert_at_end(equal,temp->data);
        }
        else
        {
            larger = insert_at_end(larger,temp->data);
        }
        temp=temp->next;
    }
    

    struct node* temps=smaller;
    struct node* tempe = equal;

    while(temps->next!=NULL)
    {
        temps=temps->next;
    }

    while(tempe->next!=NULL)
    {
        tempe=tempe->next;
    }

    temps->next=equal;
    tempe->next=larger;

    head = smaller;

    return head;
}

void printLL(struct node* head)
{
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}


int main()
{
    int n;
    struct node* head=NULL;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int num=0;
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    for(int i=0;i<n;i++)
    {
        head = insert_at_end(head,arr[i]);
    }
    printLL(head);
    printf("Enter the number by wich the partition is to be made: ");
    int x;
    scanf("%d",&x);
    head=partition(head,x);
    printLL(head);






    return 0;
}
