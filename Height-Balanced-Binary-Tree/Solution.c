#include "stdafx.h"
#include "math.h"
#include "stdio.h"
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

bool is_BSTHeight_Balanced(struct node *root){
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if ((root->left == NULL && root->right->left == NULL) && (root->left == NULL && root->right->right == NULL))
		return true;
	if ((root->right == NULL && root->left->left == NULL) && (root->right == NULL && root->left->right == NULL))
		return true;
	if ((root->left == NULL && root->right->left != NULL) || (root->left == NULL && root->right->right!=NULL))
		return false;
	if ((root->right == NULL && root->left->left != NULL) || (root->right == NULL&& root->left->right != NULL))
		return false;
	is_BSTHeight_Balanced(root->left);
	is_BSTHeight_Balanced(root->right);
}


int main(){
	struct node *BST = NULL;
	addNode(&BST, 4);
	addNode(&BST, 2);
	addNode(&BST, 7);
	addNode(&BST, 1);
	addNode(&BST, 3);
	addNode(&BST, 6);
	addNode(&BST, 9);
	addNode(&BST, 10);
	addNode(&BST, 11);
	if (is_BSTHeight_Balanced(BST))
		printf("\nTree is height balanced!\n");
	else
		printf("\nTree is NOT height balanced!\n");
	return 0;
}
