#include <stdio.h>
#include "SequentialStack.h"
#include <math.h>

int getNumOfExpression(char* postfixExpression, double numberArray[]);
int Priority(char c){
	switch(c){
		case '(': return 0; break;
		case '+': return 1; break;
		case '-': return 1; break;
		case '*': return 2; break;
		case '/': return 2; break;
	}
}


int infixToPostfix(char* infixExpression, char postfixExpression[]){
	charStack* s = charCreateStack();
	int index = 0;
	int numIndex = 0;
	while(infixExpression[index] != '\0'){
		if(infixExpression[index] != '+' && infixExpression[index] != '-' && infixExpression[index] != '*' && infixExpression[index] != '/' && infixExpression[index] != '(' && infixExpression[index] != ')'){
			postfixExpression[numIndex++] = infixExpression[index];
		}
		else if(infixExpression[index] == '('){
			charPush(s, infixExpression[index]);
		}
		else if(infixExpression[index] == '+' || infixExpression[index] == '-' || infixExpression[index] == '*' || infixExpression[index] == '/' || infixExpression[index] == ')'){
			if(charIsEmpty(s)){
				postfixExpression[numIndex++] = ' ';
				charPush(s, infixExpression[index]);
			}
			else{

				if(infixExpression[index] == ')'){
					postfixExpression[numIndex++] = ' ';

					while(charGetTop(s) != '('){
						postfixExpression[numIndex++] = charPop(s);
					}
					charPop(s);
				}
				else{
					if(Priority(infixExpression[index]) > Priority(charGetTop(s))){
						postfixExpression[numIndex++] = ' ';
						charPush(s, infixExpression[index]);
					}
					else if(Priority(infixExpression[index]) <= Priority(charGetTop(s))){
						postfixExpression[numIndex++] = charPop(s);
						charPush(s, infixExpression[index]);
						index++;
						continue;
					}
				}
			}

		}
		index++;
	}
    while(!charIsEmpty(s)){
    	postfixExpression[numIndex++] = charPop(s);
    }

    return 1;
}

int computeValueFromPostfix(char* postfixExpression, double *value){
	double numberArray[100] = {0.0};
	int numIndex = 0;
	int number = getNumOfExpression(postfixExpression, numberArray);
	doubleStack* ds = doubleCreateStack();
	int i = 0;
	while(numIndex <= number){
		double num1,num2 = 0.0;

		if(numberArray[numIndex] == -1.0 || numberArray[numIndex] == -2.0 || numberArray[numIndex] == -3.0 || numberArray[numIndex] == -4.0){
			num1 = doublePop(ds);
			num2 = doublePop(ds);

			switch((int)numberArray[numIndex]){
				case -1:
						doublePush(ds,  num2 + num1);
						break;
				case -2:
						doublePush(ds,  num2 - num1);
						break;
				case -3:
						doublePush(ds,  num2 * num1);
						break;
				case -4:
						doublePush(ds,  (double)num2 / num1);
						break;
 			}
		}
		else{
			doublePush(ds, numberArray[numIndex]);
		}
		numIndex++;

	}

	for(int i = 0; i < 100; i++)
        postfixExpression[i] = '\0';
    *value = (double)(doublePop(ds)/1.0);
    //printf("sizeof value: %d\n", sizeof(*value));
    return 1;
}

int getNumOfExpression(char* postfixExpression, double numberArray[]){
	doubleStack* ds = doubleCreateStack();
	int postIndex = 0;
	int numArrayIndex = 0;
	while(postfixExpression[postIndex] != '\0'){
		if(postfixExpression[postIndex] == '+' || postfixExpression[postIndex] == '-' || postfixExpression[postIndex] == '*' || postfixExpression[postIndex] == '/' || postfixExpression[postIndex] == ' '){
			if(!doubleIsEmpty(ds)){
				int len = ds->Top;
				for(int j = 0; j < len; j++)
					numberArray[numArrayIndex] += pow(10.0, j) * doublePop(ds);
				numArrayIndex++;
			}
			switch(postfixExpression[postIndex]){
				case '+': numberArray[numArrayIndex++] = -1.0; break;
				case '-': numberArray[numArrayIndex++] = -2.0; break;
			    case '*': numberArray[numArrayIndex++] = -3.0; break;
				case '/': numberArray[numArrayIndex++] = -4.0; break;
				case ' ': break;
			}
		}
		else{
			doublePush(ds, (double)(postfixExpression[postIndex] - '0'));
		}

	    postIndex++;
	}
    return numArrayIndex-1;
}
