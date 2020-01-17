#include "Evaluation.h"
#include <stdlib.h>

#define infixLen 100
char postfixExpression[infixLen];
char code[infixLen];
double value;
int option;

void printInfix(char expression[]){
	printf("\tThe infix expression: | ");
	for(int i = 0; expression[i] != '\0' ; i++){
		if(isInteger(expression[i]))
			printf("%c", expression[i]);
		else{
			switch(expression[i]){
				case '+': printf("+"); break;
				case '-': printf("-"); break;
				case '*': printf("*"); break;
				case '/': printf("/"); break;

				case '(': printf("("); break;
				case ')': printf(")"); break;
			}
		}
		printf(" | ");
	}
	printf("\n");
}
void printCode(char expression[]){
	printf("\tThe coded expression: | ");
	for(int i = 0; expression[i] != '\0' ; i++){
		if(isInteger(expression[i]))
			printf("%c", expression[i]);
		else{
			switch(expression[i]){
				case '+': printf("+"); break;
				case '-': printf("-"); break;
				case '*': printf("*"); break;
				case '/': printf("/"); break;

				case '(': printf("("); break;
				case ')': printf(")"); break;
				case ' ': printf(""); break;
			}
		}
		printf(" | ");
	}
	printf("\n");
}

void fileInput(){
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
  int i, k = 1;

	// CHANGE TEXT FILE HERE!!! //
	stream = fopen("expressions.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
    // Get rid of last character.
    i = 0;
    while(line[i]!='\0'){
      i++;
    }
    line[i-1] = '\0';
    // Evaluate each line.
		printf("---------------------      Test %d       ------------------------\n", k);
    if (getPostfix(line, postfixExpression) == 1){
			printInfix(line);
			printCode(line);
      printf("\tThe postfix expression: %s\n", postfixExpression);
      if(EvaluatePostfix(postfixExpression, &value) == 1)
        printf("\tThe value of the expression: %g\n\n", value);
      else
        printf("   Sorry, we can't evaluate such a postfix expression.\n");
		}else
			printf("   ... Sorry, we can't turn such an infix expression to a postfix expression.\n");

    i++;
		k++;
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
void keyInput(){
  char properInfixExpressions[infixLen];
  printf("   Which expression do you want to evaluate?\n\t>> ");
  scanf("%s", &properInfixExpressions);
//Evaluation.
  if (getPostfix(properInfixExpressions, postfixExpression) == 1){
		printInfix(properInfixExpressions);
		printCode(properInfixExpressions);
    printf("\tThe postfix expression: %s\n", postfixExpression);
    if (EvaluatePostfix(postfixExpression, &value) == 1)
      printf("\tThe value of the expression: %g\n\n", value);
    else
      printf("   ... Sorry, we can't evaluate such a postfix expression.");
  }else{
			printf("   ... Sorry, we can't turn such an infix expression to a postfix expression.\n");
  }
}

int main() {
  printf("\n   Choose a structure a type of input :\n\t\t(1) Keyboard Input\n\t\t(2) File Input\n\t>> ");
  do {
    scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
    case 1: keyInput(); break; //Case user chooses Keyboard Input
    case 2: fileInput(); break; //Case user chooses Input from file
  }
    return 0;
}
