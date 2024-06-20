#include "infix_to_postfix.h"
#include "stack.h" //REMINDER: DUMMY, TO CHANGE INTO STACK FILE'S HEADER
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Set a hierarchy/ "precedence"
int precedence(char op) {
    switch (op) {
        case '!': return 5;
        case '^': return 4;
        case '*': case '/': case '%': return 3;
        case '+': case '-': return 2;
        case '>': case '<': case '=': case '!': return 1;
        case '&': case '|': return 0;
        default: return -1;
    }
}

//check ^ and !  orr to check right associative 
int isRightAssoc(char op) {
    return op == '^' || op == '!';
}


//to check if char is an operator not an operand/num
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
           c == '^' || c == '>' || c == '<' || c == '=' || c == '!' ||
           c == '&' || c == '|';
}

//convertion or evaluation 
void infixToPostfix(char* infix, Queue *postfixQueue) {
//reminder: double check variables in other files
    CharStack operatorStack;
    initCharStack(&operatorStack);
    char token[10];
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            j = 0;
            while (isdigit(infix[i])) {
                token[j++] = infix[i++];
            }
            token[j] = '\0';
            enqueue(postfixQueue, token);
            i--;
        }
        else if (infix[i] == '(') {
            pushCharStack(&operatorStack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (!isEmptyCharStack(&operatorStack) && peekCharStack(&operatorStack) != '(') {
                c = popCharStack(&operatorStack);
                token[0] = c;
                token[1] = '\0';
                enqueue(postfixQueue, token);
            }
            popCharStack(&operatorStack); // Pop the '('
        }
        else if (isOperator(infix[i])) {
            while (!isEmptyCharStack(&operatorStack) && precedence(peekCharStack(&operatorStack)) >= precedence(infix[i])) {
                c = popCharStack(&operatorStack);
                token[0] = c;
                token[1] = '\0';
                enqueue(postfixQueue, token);
            }
            pushCharStack(&operatorStack, infix[i]);
        }
        i++;
    }

    while (!isEmptyCharStack(&operatorStack)) {
        c = popCharStack(&operatorStack);
        token[0] = c;
        token[1] = '\0';
        enqueue(postfixQueue, token);
    }
}
