#include "stdafx.h"
#include "stdlib.h"

struct node{
	int value;
	struct node *left;
	struct node *right;
};

void addNode(struct node **BST, int n){
	struct node *current = *BST;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->value = n;
	temp->left = NULL;
	temp->right = NULL;
	if (current == NULL){
		*BST = temp;
		return;
	}
	else
	{
		if (n < current->value)
			addNode(&(current->left), n);
		else
			addNode(&(current->right), n);
	}
}

//void displayTree()
void invertTree(struct node **BST){
	struct node *current = *BST;
	if (current == NULL)
		return;
	else{
		struct node *temp;
		temp = current->left;
		current->left = current->right;
		current->right = temp;
	}
	invertTree(&current->left);
	invertTree(&current->right);
}


int main()
{
	struct node *BST = NULL;
	addNode(&BST, 4);
	addNode(&BST, 2);
	addNode(&BST, 7);
	addNode(&BST, 1);
	addNode(&BST, 3);
	addNode(&BST, 6);
	addNode(&BST, 9);
	//displayTree(BST);
	invertTree(&BST);
	return 0;
}
