#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

struct stack
{   int size;
    char *data;
    int top;
};

struct stack* create_stack(int size)
{   struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->data = (char*)malloc(sizeof(char)*size);
    s->top = -1;
    return s;
}

void push(struct stack *s, char data)
{   if(s->top == s->size-1)
    {   printf("Stack Overflow");
    
    }
    else
    {
        s->top++;
        s->data[s->top] = data;
    }
}

char pop(struct stack *s)
{   char data;
    if(s->top == -1)
    {   printf("Stack Underflow");
        return -1;
    }
    else
    {   data = s->data[s->top];
        s->top--;
        return data;
    }
}

bool is_empty(struct stack *s)
{   if(s->top == -1)
        return true;
    else
        return false;
}

int postfix_evaluation(char* exp)
{
    struct stack* s;
    s = create_stack(strlen(exp));
    int i;
for(i=0;exp[i]!='\0';i++)
{
    if(isdigit(exp[i]))
    {
        push(s,exp[i]-'0');
    }
    else
    {
        int op2 = pop(s);
        int op1 = pop(s);
        switch(exp[i])
        {
            case '+':
            push(s,op1+op2);
            break;
            case '-':
            push(s,op1-op2);
            break;
            case '*':
            push(s,op1*op2);
            break;
            case '/':
            push(s,op1/op2);
            break;
        }
    }

    
}
return pop(s);
}

int main()
{   char exp[100];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    printf("The result is: %d",postfix_evaluation(exp));
}
