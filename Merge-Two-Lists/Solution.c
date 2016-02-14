#include "stdafx.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *next;
};

void addNode(struct node **root, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *current = *root;
	temp->data = data;
	temp->next = NULL;
	if (current == NULL){
		*root = temp;
		return;
	}
	else{
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
}

void merge(struct node**first, struct node ** second){
	struct node *first_curr = *first;
	struct node *second_curr = *second;
	struct node *prev = NULL;
	while (first_curr->next != NULL && second_curr->next != NULL){
		if (second_curr->data < first_curr->data && prev==NULL){
			struct node *temp = second_curr;
			second_curr = second_curr->next;
			temp->next = first_curr;
			first_curr = temp;
			*first = first_curr;
			continue;
		}
		if (second_curr->data > first_curr->data && second_curr->data<first_curr->next->data){
			struct node *temp = second_curr;
			second_curr = second_curr->next;
			temp->next = first_curr->next;
			first_curr->next = temp;
			first_curr = first_curr->next;
			continue;
		}
		if (second_curr->data > first_curr->data && second_curr->data > first_curr->next->data){
			first_curr = first_curr->next;
		}
		if (second_curr->data > first_curr->data && second_curr->data == first_curr->next->data){
			second_curr = second_curr->next;
			continue;
		}
		if (second_curr->data == first_curr->data)
			second_curr = second_curr->next;
	}
	if (first_curr->next != NULL && second_curr != NULL){
		while (first_curr->next != NULL)
			first_curr = first_curr->next;
		first_curr->next = second_curr;
	}
}


void display(struct node *root){
	struct node *current = root;
	while (current != NULL){
		printf("%d\t", current->data);
		current = current->next;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *first = NULL;
	struct node *second = NULL;
	addNode(&first, 5);
	addNode(&first, 7);
	addNode(&first, 9);
	addNode(&first, 11);
	addNode(&first, 13);
	addNode(&first, 15);
	addNode(&second, 2);
	addNode(&second, 4);
	addNode(&second, 6);
	addNode(&second, 8);
	addNode(&second, 10);
	addNode(&second, 12);
	addNode(&second, 14);
	addNode(&second, 15);
	addNode(&second, 16);
	display(first);
	printf("\n\n");
	display(second);
	merge(&first, &second);
	printf("\n\n");
	display(first);
	return 0;
}
