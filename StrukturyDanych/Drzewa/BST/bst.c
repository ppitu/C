#include <stdio.h>
#include <stdlib.h>

typedef int myVar;

struct node
{
	myVar data;
	struct node *leftChild;
	struct node *rightChild;
};

struct node *newNode(myVar data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->leftChild = temp->rightChild = NULL;
	return temp;
};

struct node* insert(struct node *node, myVar data)
{

	//if tree is empty, create root node
	if(node == NULL)
		return  newNode(data);

	if(data < node->data)
		node->leftChild = insert(node->leftChild, data);
	else if(data > node->data)
		node->rightChild = insert(node->rightChild, data);

	return node;
		
}

struct node *minValueNode(struct node* node)
{
	struct node* current = node;

	while(current && current->leftChild != NULL)
		current = current->leftChild;

	return current;
}

struct node* deleteNode(struct node* root, myVar data)
{
	//base case
	if(root == NULL)
		return root;

	if(data < root->data)
		root->leftChild = deleteNode(root->leftChild, data);
	else if(data > root->data)
		root->rightChild = deleteNode(root->rightChild, data);
	else
	{
		if(root->leftChild == NULL)
		{
			struct node *temp = root->rightChild;
			free(root);
			return temp;
		}
		else if(root->rightChild == NULL)
		{
			struct node *temp = root->leftChild;
			free(root);
			return temp;
		}

		struct node *temp = minValueNode(root->rightChild);

		root->data = temp->data;

		root->rightChild = deleteNode(root->rightChild, data);
	}

	return root;
}

struct node* search(myVar data, struct node* root)
{
	struct node *current = root;
	
	while(current->data != data)
	{
		//go to left tree

		if(current->data > data)
		{
			current = current->leftChild;
		}
		//else go to right tree
		else
		{ 
			current = current->rightChild;
		}

		//not found
		if(current == NULL)
			return NULL;

	}

	return current;
}	


void preOrder(struct node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

void inOrder(struct node* root)
{
	if(root != NULL)
	{
		inOrder(root->leftChild);
		printf("%d ", root->data);
		inOrder(root->rightChild);
	}
}

void postOrder(struct node* root)
{
	if(root != NULL)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		printf("%d ", root->data);
	}
}


