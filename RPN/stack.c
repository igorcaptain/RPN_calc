#include "stack.h"

Stack_i* createStack(unsigned int capacity) {
	Stack_i* stack = (Stack_i*)malloc(sizeof(Stack_i));
	stack->capacity = capacity;
	stack->top = -1;
	stack->data = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

void deleteStack(Stack_i* stack) {
	free(stack->data);
	free(stack);
}

int isFull(Stack_i* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack_i* stack) {
	return stack->top == -1;
}

void push(Stack_i* stack, int item) {
	if (isFull(stack)) {
		printf("Is overflow!\n");
		return;
	}
	stack->data[++stack->top] = item;
}

int pop(Stack_i* stack) {
	if (isEmpty(stack)) {
		printf("Is void!\n");
		return INT_MIN;
	}
	return stack->data[stack->top--];
}

int top(Stack_i* stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->data[stack->top];
}

/*
int main() {
	Stack_i* stack = createStack(1);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 30);
	push(stack, 10);


	printf("%d is from top\n", top(stack));
	printf("%d popped\n", pop(stack));
	printf("%d is from top\n", top(stack));
	pop(stack);
	pop(stack);
	pop(stack);

	deleteStack(stack);
	_getch();
	return 0;
}
*/
