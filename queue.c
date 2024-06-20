#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the queue
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmptyQueue(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFullQueue(Queue *queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Add a value to the queue
void enqueue(Queue *queue, char *value) {
    if (isFullQueue(queue)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    if (isEmptyQueue(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    strcpy(queue->items[queue->rear], value);
}

// Remove and return a value from the queue
char* dequeue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    char *value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return value;
}

// Peek at the front value of the queue without removing it
char* peekQueue(Queue *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->items[queue->front];
}
