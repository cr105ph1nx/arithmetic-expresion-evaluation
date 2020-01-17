#ifndef _EVALUATION_H_
#define _EVALUATION_H_
#include<stdio.h>

int isInteger(char c);
int getPostfix(char* infoxExpression, char postfixExpression[]);
int EvaluatePostfix(char* postfixExpression, double *value);
int Priority(char c);
int expressionNum(char* postfixExpression, double numberArray[]);

#endif
