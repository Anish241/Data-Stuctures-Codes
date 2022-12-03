#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *next;
}*stack=NULL;

void push(char data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=stack;
    stack=temp;
}

char pop()
{
    struct node *temp;
    char data;
    temp=stack;
    data=temp->data;
    stack=stack->next;
    free(temp);
    return data;
}

bool isPalindrome(char*str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=pop())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    if(isPalindrome(str))
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}