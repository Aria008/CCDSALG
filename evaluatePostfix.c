#include "evaluate_postfix.h"
#include "stack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int evaluatePostfix(Queue *postfixQueue, char* error) { //uses pointer to the postfix
    IntStack operandStack;
    initIntStack(&operandStack);
    char *token;
    char num[10];
    int op1, op2, result;// op1 and op 2 is to store operands and result to store reuslt

    //loop to keep goin while postfixQueue is not empty
    while (!isEmptyQueue(postfixQueue)) {
        token = dequeue(postfixQueue);

        if (isdigit(token[0])) {
            pushIntStack(&operandStack, atoi(token));
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '%') {
            if (sizeIntStack(&operandStack) < 2) {
                strcpy(error, "Invalid postfix expression: insufficient operands");
                return 0;
            }
            op2 = popIntStack(&operandStack);
            op1 = popIntStack(&operandStack);
            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        strcpy(error, "Division by zero error!");
                        return 0;
                    }
                    result = op1 / op2;
                    break;
                case '%':
                    if (op2 == 0) {
                        strcpy(error, "Division by zero error!");
                        return 0;
                    }
                    result = op1 % op2;
                    break;
            }
            pushIntStack(&operandStack, result);
        } else {
            strcpy(error, "Invalid token found in postfix expression");
            return 0;
        }
    }
    return popIntStack(&operandStack);
}
