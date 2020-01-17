#ifndef _SSTACK_H_
#define _SSTACK_H_
#define MAXSIZE 1000

typedef struct {
	int* array;
	int Top;
	int len;
}intStack;

intStack* intCreateStack();
void intPush(intStack* PtrS, int item);
int intPop(intStack* PtrS);
int intIsEmpty(intStack* S);
void intClearStack(intStack* PtrS);
int intGetTop(intStack* s);

typedef struct {
	char* array;
	int Top;
	int len;
}charStack;

charStack* charCreateStack();
void charPush(charStack* PtrS, char item);
char charPop(charStack* PtrS);
int charIsEmpty(charStack* S);
void charClearStack(charStack* PtrS);
char charGetTop(charStack* s);

typedef struct {
	double* array;
	int Top;
	int len;
}doubleStack;

doubleStack* doubleCreateStack();
void doublePush(doubleStack* PtrS, double item);
double doublePop(doubleStack* PtrS);
int doubleIsEmpty(doubleStack* S);
void doubleClearStack(doubleStack* PtrS);
double doubleGetTop(doubleStack* s);


#endif
