#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

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

void infix_to_postfix(char *infix)
{   struct stack *s;
    s = create_stack(strlen(infix));
    char c;
    int i=0, j=0;
    char *postfix;
    postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    while(infix[i] != '\0')
    {   
        if(infix[i]=='(')
        {
            push(s, infix[i]);
            i++;
        }
        else if(infix[i] == ')')
        {   while((c = pop(s)) != '(')
            {   postfix[j] = c;
                j++;
            }
            i++;
        }
        else if(is_operator(infix[i]))
        {   if(precedence(infix[i]) > precedence(s->data[s->top]))
            {   push(s, infix[i]);
                i++;
            }
            else
            {   postfix[j] = pop(s);
                j++;
            }
        }
        else
        {   postfix[j] = infix[i];
            j++;
            i++;
        }
        
        
    }
    while(!is_empty(s))
    {   postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    printf("%s", postfix);
}

int main()
{   char infix[20];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}
