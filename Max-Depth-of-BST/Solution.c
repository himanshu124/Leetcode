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

int depth(struct node **BST){
	struct node *temp = *BST;
	if (temp == NULL){
		return 0;
	}
	else{
		int rdepth = depth(&temp->right) + 1;
		int ldepth = depth(&temp->left) + 1;
		if (rdepth > ldepth)
			return rdepth;
		else
			return ldepth;
	}
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
	addNode(&BST, 10);
	//displayTree(BST);
	printf("\n%d",depth(&BST));
	return 0;
}
