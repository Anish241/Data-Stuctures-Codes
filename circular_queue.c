#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

struct circular_queue
{   int size;
    int *data;
    int front;
    int rear;
};

struct circular_queue* create_queue(int size)
{   struct circular_queue *q;
    q = (struct circular_queue*)malloc(sizeof(struct circular_queue));
    q->size = size;
    q->data = (int*)malloc(sizeof(int)*size);
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct circular_queue *q, int data)
{   if((q->rear+1)%q->size == q->front)
    {   printf("Queue Overflow\n");
    
    }
    else
    {   if(q->front == -1)
            q->front = 0;
        q->rear = (q->rear+1)%q->size;
        q->data[q->rear] = data;
    }
}

int dequeue(struct circular_queue *q)
{   int data;
    if(q->front == -1)
    {   printf("Queue Underflow\n");
        return -1;
    }
    else
    {   data = q->data[q->front];
        if(q->front == q->rear)
        {   q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front+1)%q->size;
        return data;
    }
}

bool is_empty(struct circular_queue *q)
{   if(q->front == -1)
        return true;
    else
        return false;
}

void print_queue(struct circular_queue *q)
{   int i;
    if(q->front == -1)
        printf("Queue is empty");
    else
    {   for(i=q->front;i!=q->rear;i=(i+1)%q->size)
            printf("%d ",q->data[i]);
        printf("%d ",q->data[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    struct circular_queue *q;
    q = create_queue(size);
    int choice;
    while(1)
    {
        printf("Choose the operations to be performed: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print the queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {   case 1: printf("Enter the element to be enqueued: ");
                    int data;
                    scanf("%d", &data);
                    enqueue(q, data);
                    break;
            case 2: printf("The dequeued element is: %d\n", dequeue(q));
                    break;
            case 3: print_queue(q);
                    break;
            case 4: exit(0);

        }


    }
}