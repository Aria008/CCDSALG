#ifndef STACK_H
#define STACK_H

#define MAX 100 

typedef struct {
    char items[MAX];
    int top;
} CharStack;

// Function prototypes
void initCharStack(CharStack *stack);
int isEmptyCharStack(CharStack *stack);
int isFullCharStack(CharStack *stack);
void pushCharStack(CharStack *stack, char value);
char popCharStack(CharStack *stack);
char peekCharStack(CharStack *stack);

typedef struct {
    int data[MAX];
    int top;
} IntStack;

// Function prototypes for IntStack
void initIntStack(IntStack *stack);
int isEmptyIntStack(IntStack *stack);
int isFullIntStack(IntStack *stack);
void pushIntStack(IntStack *stack, int value);
int popIntStack(IntStack *stack);
int peekIntStack(IntStack *stack);

#endif // STACK_H
