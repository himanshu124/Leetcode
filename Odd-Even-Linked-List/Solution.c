#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

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

void display(struct node *root){
	struct node *current = root;
	while (current != NULL){
		printf("%d\t", current->data);
		current = current->next;
	}
}

void rearrange(struct node **root){
	struct node *odd = *root;
	struct node *e = odd->next;
	struct node *even = odd->next;
	while (odd->next != NULL && even->next!=NULL){
		odd->next = odd->next->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	odd->next = e;
}

int main(){
	struct node *root = NULL;
	addNode(&root, 6);
	addNode(&root, 2);
	addNode(&root, 8);
	addNode(&root, 0);
	addNode(&root, 4);
	addNode(&root, 7);
	addNode(&root, 9);
	addNode(&root, 3);
	addNode(&root, 5);
	display(root);
	rearrange(&root);
	printf("\n");
	display(root);
	return 0;
}
