#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *next;
};

struct node* create_node(char data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert_node(struct node **head, char data)
{
    struct node *n;
    n = create_node(data);
    if(*head == NULL)
        *head = n;
    else
    {   struct node *temp;
        temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}



bool is_palindrome(struct node *head)
{
    struct node *temp;
    temp = head;
    int len = 0;
    while(temp != NULL)
    {   len++;
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    while(i < len/2)
    {   i++;
        temp = temp->next;
    }
    struct node *temp2;
    temp2 = temp;
    temp = head;
    i = 0;
    while(i < len/2)
    {   i++;
        temp2 = temp2->next;
    }
    if(len%2 != 0)
        temp2 = temp2->next;
    while(temp2 != NULL)
    {   if(temp->data != temp2->data)
            return false;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return true;
}

int main()

{
    struct node *head;
    head = NULL;
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int i = 0;
    while(str[i] != '\0')
    {   insert_node(&head, str[i]);
        i++;
    }
    
    if(is_palindrome(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}


