#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize the stack
void initCharStack(CharStack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmptyCharStack(CharStack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFullCharStack(CharStack *stack) {
    return stack->top == MAX - 1;
}

// Push a value onto the stack
void pushCharStack(CharStack *stack, char value) {
    if (isFullCharStack(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

// Pop a value from the stack
char popCharStack(CharStack *stack) {
    if (isEmptyCharStack(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Peek at the top value of the stack without popping it
char peekCharStack(CharStack *stack) {
    if (isEmptyCharStack(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}
