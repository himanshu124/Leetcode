#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void addNode(struct node **root, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *current = *root;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if (current == NULL){
		*root = temp;
		return;
	}
	else{
		if (temp->data < current->data)
			addNode(&(current->left), data);
		else
			addNode(&(current->right), data);
	}
}

bool nodeExist(struct node **root, int data){
	struct node *current = *root;
	if (current == NULL)
		return false;
	if (current->data == data)
		return true;
	if (data < current->data)
		nodeExist(&(current->left), data);
	else
		nodeExist(&(current->right), data);
}


int LCA(struct node **root, int a, int b){
	struct node* current = *root;
	struct node* lca = *root;
	if ((a<lca->data && b>lca->data) || (a>lca->data && b < lca->data)){
		if (nodeExist(&lca, a)&& nodeExist(&lca,b))
			return lca->data;
		else
			return -1;
	}
	if ((a < lca->data) && (b < lca->data)){
		return LCA(&(lca->left), a, b);
	}
	if ((a > lca->data) && (b > lca->data)){
		return LCA(&(lca->right), a, b);
	}
	if (a == lca->data){
		if (nodeExist(&lca, b))
			return a;
	}
	if (b == lca->data){
		if (nodeExist(&lca, a))
			return b;
	}
	return -1;
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
	printf("LCA is %d", LCA(&root, 2, 6));
	return 0;
}
