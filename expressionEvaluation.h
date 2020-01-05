#ifndef _EXPRESSIONEVALUATION_H_
#define _EXPRESSIONEVALUATION_H_
#include<stdio.h>
int infixToPostfix(char* infoxExpression, char postfixExpression[]);
int computeValueFromPostfix(char* postfixExpression, double *value);
int Priority(char c);
int getNumOfExpression(char* postfixExpression, double numberArray[]);

#endif
