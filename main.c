#include "expressionEvaluation.h"
#include <stdlib.h>

#define testNumbers 3
#define infixLength 100
char postfixExpression[infixLength];
double value;
int option;

void fileInput(){
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
  int i, k = 1;

	stream = fopen("expressions.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
    //deletes newline.
    i = 0;
    while(line[i]!='\0'){
      i++;
    }
    line[i-1] = '\0';
    //do evaluation here.
        printf("---------------------      Test %d       ------------------------\n\n", k);

        printf("\tThe infix expression: %s\n", line);
        if (infixToPostfix(line, postfixExpression) == 1){
            printf("\tThe postfix expression: %s\n", postfixExpression);
            if (computeValueFromPostfix(postfixExpression, &value) == 1)
                printf("\tThe value of the expression: %g\n\n", value);
            else
                printf("Sorry, we can't evaluate such a postfix expression.");

        }
        else{
            printf("Sorry, we can't turn such an infix expression to a postfix expression.");
        }

        i++;
    }

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

void userInput(){
  char properInfixExpressions[infixLength];
  printf("\tWhich expression do you want to evaluate?\n\t>> ");
  scanf("%s", &properInfixExpressions);

//evaluation.
  printf("\tThe infix expression: %s\n", properInfixExpressions);
  if (infixToPostfix(properInfixExpressions, postfixExpression) == 1){
      printf("\tThe postfix expression: %s\n", postfixExpression);
      if (computeValueFromPostfix(postfixExpression, &value) == 1)
          printf("\tThe value of the expression: %g\n\n", value);
      else
          printf("... Sorry, we can't evaluate such a postfix expression.");

  }
  else{
      printf("... Sorry, we can't turn such an infix expression to a postfix expression.");
  }

}

int main() {
  printf("\tChoose a structure a type of input :\n\t\t(1) User Input\n\t\t(2) Input From File\n\t>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1: userInput(); break;

      case 2: fileInput(); break;
  }

    return 0;
}
