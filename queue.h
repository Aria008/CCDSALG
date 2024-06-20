#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100
#define MAX_TOKEN_LENGTH 10

typedef struct {
    char items[MAX_QUEUE_SIZE][MAX_TOKEN_LENGTH + 1];
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
