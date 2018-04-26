#pragma once
#include <malloc.h>
#include <stdio.h>
#include <limits.h>

typedef struct Stack {
	int *data;
	int top;
	int capacity;
} Stack_i;

Stack_i* createStack(unsigned int);
void deleteStack(Stack_i *stack);
int isEmpty(Stack_i *stack);
int isFull(Stack_i *stack);
void push(Stack_i *stack, int item);
int pop(Stack_i *stack);
int top(Stack_i *stack);
