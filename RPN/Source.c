
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "stack.h"

#define SIZE 80


char* infix_to_postfix(char infix[], char postfix[]);
int precedence(char);
int calculate(char postfix[]);



int main() {

	char *infix = (char *)malloc(SIZE * sizeof(char));
	char *postfix = (char *)malloc(SIZE * sizeof(char));
	memset(infix, 0, SIZE * sizeof(char));
	memset(postfix, 0, SIZE * sizeof(char));

	int result;
		
	printf("Input your arithmetic expression (use ' ' between tokens)->");
	fgets(infix, SIZE, stdin);
	infix[strlen(infix) - 1] = '\0';

	infix_to_postfix(infix, postfix);
	result = calculate(postfix);

	printf("Reverse polish note: %s\n", postfix);
	printf("Result = %d\n", result);


	free(infix);
	free(postfix);

	system("pause");
	return 0;
}

char* infix_to_postfix(char* infix, char* postfix) {
	int i = 0, j = 0, k = 0;
	Stack_i *lifo = createStack(20);
	int q=0;

	char zn=0;
	char *token = strtok(infix, " ");
	while (token)
	{
		if (isdigit(*token)) {
			for (k = 0; k < strlen(token); k++)
				postfix[j + k] = *(token + k);
			postfix[j + k] = ' ';
			j += k + 1;
		}
		else
			if (*token == '(')
				push(lifo, '(');
			else
				if (*token == ')') {
					while ((zn = pop(lifo)) != '(') {
						postfix[j++] = zn;
						postfix[j++] = ' ';
					}
				}
				else
				{
					while (precedence(*token) <= precedence(top(lifo)) && !isEmpty(lifo))
					{
						zn = pop(lifo);
						postfix[j++] = zn;
						postfix[j++] = ' ';
					}
					push(lifo, *token);
				}

		token = strtok(NULL, " ");
	}
	while (!isEmpty(lifo)) {
		zn = pop(lifo);
		postfix[j++] = zn;
		postfix[j++] = ' ';
	}
	postfix[j] = '\0';
	deleteStack(lifo);
	return postfix;
}

int precedence(char x)
{
	if (x == '(')
		return(0);
	if (x == '+' || x == '-')
		return(1);
	if (x == '*' || x == '/')
		return(2);
	return(3);
}

int calculate(char* postfix) {
	int i = 0, j = 0, k = 0;
	char *buf = (char *)malloc((strlen(postfix) + 1) * sizeof(char));
	strcpy(buf, postfix);
	int a=0, b=0;
	Stack_i *lifo = createStack(20);

	char zn;
	char *token = strtok(buf, " ");
	while (token)
	{
		if (isdigit(*token)) {
			a = atoi(token);
			push(lifo, a);
		}
		else {
			switch (*token) {
			case ' ': break;
			case '+':
				push(lifo, pop(lifo) + pop(lifo));
				break;
			case '-':
				a = pop(lifo);
				b = pop(lifo);
				push(lifo, b - a);
				break;
			case '*':
				push(lifo, pop(lifo) * pop(lifo));
				break;
			case '/':
				a = pop(lifo);
				b = pop(lifo);
				push(lifo, b / a);
				break;
			}
		}
		token = strtok(NULL, " ");
	}

	free(buf);
	int result = pop(lifo);
	deleteStack(lifo);
	return result;
}