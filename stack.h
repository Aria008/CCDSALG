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

#endif // STACK_H
