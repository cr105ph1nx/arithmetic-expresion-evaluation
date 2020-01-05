#include "expressionEvaluation.h"

#define testNumbers 3
#define infixLength 100

int main() {
    char properInfixExpressions[testNumbers][infixLength] = { //creates a matrix with: rows = num of expressions / columns = length of expressions
        "23+(58-41+33-25*8/4/2*12/3)/(49+1)",
        "2-(5+5*4+3*2-1)/(27+3*1)",
        "3/2"
    }; //change later to user giving expression

    char postfixExpression[infixLength];
    double value;


    for (int i = 0; i < testNumbers; i++) {
        printf("---------------------      Test %d       ------------------------\n\n", i + 1);
        printf("\tThe infix expression: %s\n", properInfixExpressions[i]);
        if (infixToPostfix(properInfixExpressions[i], postfixExpression) == 1){
            printf("\tThe postfix expression: %s\n", postfixExpression);
            if (computeValueFromPostfix(postfixExpression, &value) == 1)
                printf("\tThe value of the expression: %g\n\n", value);
            else
                printf("Sorry, we can't evaluate such a postfix expression.");

        }
        else{
            printf("Sorry, we can't turn such an infix expression to a postfix expression.");
        }
    }

    return 0;
}
