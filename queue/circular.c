#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct queue
{
    int front;
    int rear;
    int *array;
    int capacity;
    int size;
};

typedef struct queue queue;

queue *getQueue(int capacity)
{
    queue *temp;
    temp = (queue *)malloc(sizeof(queue) * capacity);
    temp->size = 0;
    temp->front = temp->rear = -1;
    temp->array = malloc(sizeof(capacity) * sizeof(int));
    return temp;
}

int getSize(queue *que)
{
    return (que->size);
}

int isEmpty(queue *que)
{
    return (que->front == que->rear && que->rear == -1);
}

int isFull(queue *que)
{
    return (que->size==que->capacity);
}

void enque(queue *que, int ele)
{
     if (isFull(que))
     {
         printf("full queue");
     }
     else
     {
        (que->rear)++;
        que->array[que->rear] = ele;
     }
     (que->size++);
}

void deque(queue *que)
{
    if (isEmpty(que))
    {
        printf("empty queue\n");
    }
    else if (que->rear == 0)
    {
        que->rear = -1;
    }
    else
    {
        (que->rear)--;
    }
}

void display(queue *que){
    queue *temp;
    // temp->front=que->front;
    int count=0;
    (que->front)++;
    while (que->front!=que->rear)
    {
        printf("%d", que->array[count]);
        count++;
    }
    
}

int main()
{
    queue *que;
    que=getQueue(3);
    enque(que, 3);
    enque(que, 4);
    enque(que, 5);
    display(que);
    // deque(que);
    // deque(que);
    // display(que);
    // deque(que);
}