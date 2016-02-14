#include "stdafx.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void stack_push(struct node** stack, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node* curr = *stack;
	temp->next = curr;
	curr = temp;
	*stack = curr;
	return;
}

int stack_peek(struct node *stack){
	if (stack == NULL)
		return -1;
	else
		return stack->data;
}

void stack_pop(struct node **stack){
	struct node *curr = *stack;
	if (curr == NULL){
		return;
	}
	else{
		struct node *temp = curr;
		curr = curr->next;
		*stack = curr;
		free(temp);
	}
}

bool stack_isEmpty(struct node *stack){
	if (stack == NULL)
		return true;
	else
		return false;
}

void queue_push(struct node **queue, struct node **stack1, struct node **stack2,  int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node* queue_curr = *queue;
	if (queue_curr == NULL){
		queue_curr = temp;
		*queue = queue_curr;
		return;
	}
	else{
		while (queue_curr->next != NULL){
			stack_push(stack2, stack_peek(*queue));
			stack_pop(queue);
			queue_curr = *queue;
		}
		queue_curr->next = temp;
		while (!stack_isEmpty(*stack2)){
			stack_push(queue, stack_peek(*stack2));
			stack_pop(stack2);
		}
	}
}

void queue_peek(struct node *queue){
	if (queue != NULL)
		printf("\nTop: %d", queue->data);
	else
		printf("\nQueue is empty");
}

struct node* queue_pop(struct node ** queue){
	struct node *curr = *queue;
	if (curr != NULL){
		*queue = curr->next;
		return curr;
	}
	else{
		printf("\nQueue is empty");
		return NULL;
	}
}

bool queue_isEmpty(struct node *queue){
	if (queue == NULL)
		return true;
	else
		return false;
}

int main(){
	struct node* stack1 = NULL;
	struct node* stack2 = NULL; 
	struct node* queue = NULL;
	queue_push(&queue, &stack1, &stack2, 1);
	queue_push(&queue, &stack1, &stack2, 2);
	queue_push(&queue, &stack1, &stack2, 3);
	queue_push(&queue, &stack1, &stack2, 4);
	queue_peek(queue);
	struct node* popped = queue_pop(&queue);
	if (popped != NULL)
		printf("\nPopped:%d ", popped->data);
	queue_peek(queue);
	popped = queue_pop(&queue);
	if (popped != NULL)
		printf("\nPopped:%d ", popped->data);
	queue_peek(queue);
	popped = queue_pop(&queue);
	if (popped != NULL)
		printf("\nPopped:%d ", popped->data);
	queue_peek(queue);
	popped = queue_pop(&queue);
	if (popped != NULL)
		printf("\nPopped:%d ", popped->data);
	queue_peek(queue);
	popped = queue_pop(&queue);
	if (popped != NULL)
		printf("\nPopped:%d ", popped->data);
	queue_peek(queue);
	if (queue_isEmpty(queue))
		printf("\nQueue is Empty");
	else
		printf("\nQueue is not Empty");
	return 0;
}
