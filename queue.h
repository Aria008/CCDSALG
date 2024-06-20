#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100 

typedef struct {
    char items[MAX][10];
    int front, rear;
} Queue;

// Function prototypes
void initQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
int isFullQueue(Queue *queue);
void enqueue(Queue *queue, char *value);
char* dequeue(Queue *queue);
char* peekQueue(Queue *queue);

#endif // QUEUE_H
