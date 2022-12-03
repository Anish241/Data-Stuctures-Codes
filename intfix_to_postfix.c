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

void intfix_to_postfix(char *intfix)
{   struct stack *s;
    s = create_stack(strlen(intfix));
    char c;
    int i=0, j=0;
    char *postfix;
    postfix = (char*)malloc((strlen(intfix)+1)*sizeof(char));
    while(intfix[i] != '\0')
    {   
        if(intfix[i]=='(')
        {
            push(s, intfix[i]);
            i++;
        }
        else if(intfix[i] == ')')
        {   while((c = pop(s)) != '(')
            {   postfix[j] = c;
                j++;
            }
            i++;
        }
        else if(is_operator(intfix[i]))
        {   if(precedence(intfix[i]) > precedence(s->data[s->top]))
            {   push(s, intfix[i]);
                i++;
            }
            else
            {   postfix[j] = pop(s);
                j++;
            }
        }
        else
        {   postfix[j] = intfix[i];
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
{   char intfix[20];
    printf("Enter the intfix expression: ");
    scanf("%s", intfix);
    intfix_to_postfix(intfix);
    return 0;
}