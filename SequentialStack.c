#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "SequentialStack.h"


intStack* intCreateStack(){
	intStack* p = (intStack*)malloc(sizeof(intStack));
	p->array = (int*)malloc(MAXSIZE*sizeof(int));
	p->Top = 0;
	p->len = MAXSIZE;
	return p;
}
void intPush(intStack* PtrS, int item) {
	if(PtrS->Top >= PtrS->len){
		int *array =  (int*)malloc((PtrS->Top  + MAXSIZE)*sizeof(int));
		int L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(int));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;

	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%d Push success!\n", PtrS->array[PtrS->Top - 1]);

}

int intPop(intStack * PtrS){
	if(PtrS->Top == 0){
		printf("This is an empty stack!\n");
		return 0;
	}
	int data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int intIsEmpty(intStack* S) {
	if (S->Top == 0){

		//printf("This is an empty stack!\n");
		return 1;
	}
	else{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void intClearStack(intStack* PtrS){
	free(PtrS);
	//printf("ClearStack success!\n");
}

int intGetTop(intStack* s)  {
	if(s->Top == 0){
		//printf("This is an empty stack!");
		return 0;
	}
	int data =  s->array[s->Top - 1];
}


charStack* charCreateStack() {
	charStack* p = (charStack*)malloc(sizeof(charStack));
	p->array = (char*)malloc(MAXSIZE*sizeof(char));
	p->Top = 0;
	p->len = MAXSIZE;
	return p;
}

void charPush(charStack* PtrS, char item) {
	if(PtrS->Top >= PtrS->len){
		char *array =  (char*)malloc((PtrS->Top  + MAXSIZE)*sizeof(char));
		char L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(char));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;

	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%c Push success!\n", PtrS->array[PtrS->Top - 1]);

}

char charPop(charStack * PtrS) {
	if(PtrS->Top == 0){
		//printf("This is an empty stack!\n");
		return 0;
	}
	char data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int charIsEmpty(charStack* S)  {
	if (S->Top == 0){

		//printf("This is an empty stack!\n");
		return 1;
	}
	else{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void charClearStack(charStack* PtrS)  {
	free(PtrS);
	//printf("ClearStack success!\n");
}

char charGetTop(charStack* s) {
	if(s->Top == 0){
		//printf("This is an empty stack!");
		return 0;
	}
	char data =  s->array[s->Top - 1];
}


doubleStack* doubleCreateStack(){
	doubleStack* p = (doubleStack*)malloc(sizeof(doubleStack));
	p->array = (double*)malloc(MAXSIZE*sizeof(double));
	/*for (double i = 0; i < MAXSIZE; i++)
	{
		p->array[i] = 0;
	}*/
	p->Top = 0;
	p->len = MAXSIZE;
	return p;
}

void doublePush(doubleStack* PtrS, double item)   {
	if(PtrS->Top >= PtrS->len){
		double *array =  (double*)malloc((PtrS->Top  + MAXSIZE)*sizeof(double));
		double L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(double));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;

	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%f Push success!\n", PtrS->array[PtrS->Top - 1]);

}

double doublePop(doubleStack * PtrS)  {
	if(PtrS->Top == 0){
		//printf("This is an empty stack!\n");
		return 0;
	}
	double data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int doubleIsEmpty(doubleStack* S) {
	if (S->Top == 0){

		//printf("This is an empty stack!\n");
		return 1;
	}
	else{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void doubleClearStack(doubleStack* PtrS) {
	free(PtrS);
	//printf("ClearStack success!\n");
}

double doubleGetTop(doubleStack* s)    {
	if(s->Top == 0){
		//printf("This is an empty stack!");
		return 0;
	}
	double data =  s->array[s->Top - 1];
}
