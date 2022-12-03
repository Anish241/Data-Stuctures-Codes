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

bool is_operator(char c)
{   if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

int precedence(char c)
{   if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

char* infix_to_prefix(char *infix)
{   int i, j;
    char *prefix;
    struct stack *s;
    s = create_stack(strlen(infix));
    prefix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    strrev(infix);
    for(i=0, j=0; infix[i]!='\0'; i++)
    {   if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }
    for(i=0; infix[i]!='\0'; i++)
    {   if(infix[i] == '(')
            push(s, infix[i]);
        else if(isalnum(infix[i]))
        {   prefix[j] = infix[i];
            j++;
        }
        else if(is_operator(infix[i]))
        {   while(!is_empty(s) && precedence(s->data[s->top]) > precedence(infix[i]))
            {   prefix[j] = pop(s);
                j++;
            }
            push(s, infix[i]);
        }
        else if(infix[i] == ')')
        {   while((!is_empty(s)) && (s->data[s->top] != '('))
            {   prefix[j] = pop(s);
                j++;
            }
            if(s->data[s->top] == '(')
                pop(s);
        }
    }
    while(!is_empty(s))
    {   prefix[j] = pop(s);
        j++;
    }
    prefix[j] = '\0';
    strrev(prefix);
    return prefix;
}


void parenthesis(char *str)
{   int i;
    for(i=0; i<strlen(str); i++)
    {   if(str[i] == '(')
            str[i] = ')';
        else if(str[i] == ')')
            str[i] = '(';
    }
}

int main()
{   char *infix;
    infix = (char*)malloc(100*sizeof(char));
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    char *prefix;
    prefix = infix_to_prefix(infix);
    printf("Prefix: %s", prefix);
    return 0;
}


