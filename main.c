#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "infixToPostfix.h"
#include "evaluatePostfix.h"

//specs:For simplicity, assume string with at most 256 characters, including the NULL byte
#define MAX_EXPRESSION_LENGTH 256

int main() {
    char infix[MAX_EXPRESSION_LENGTH];
    Queue postfixQueue;
    char error[100];
    int result;

    initQueue(&postfixQueue);
    
    //reads infix, else ERROR
    if (!fgets(infix, sizeof(infix), stdin)) {
        printf("ERROR.\n");
        return 1;
    }

    // Remove newline character from fgets input
    infix[strcspn(infix, "\n")] = '\0';

    // infixToPostfix
    infixToPostfix(infix, &postfixQueue);

    // second line or prints postfix expression
    while (!isEmptyQueue(&postfixQueue)) {
        printf("%s ", dequeue(&postfixQueue));
    }
    printf("\n");

    // Evaluate postfix 
    strcpy(error, "");
    result = evaluatePostfix(&postfixQueue, error);

    // Print answer
    if (strcmp(error, "") == 0) {
        printf("%d\n", result);
    } else {
        printf("%s\n", error);
    }

    // clear
    initQueue(&postfixQueue);

    return 0;
}
