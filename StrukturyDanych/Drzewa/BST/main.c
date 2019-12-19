#include <stdlib.h>

#include "bst.c"

int main()
{
	struct node* root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	//struct node *temp = search(5, root);

	preOrder(root);
	printf("\n");

	deleteNode(root, 40);

	preOrder(root);	
	//inOrder(root);
	//postOrder(root);
	
	return 0;
}
