#include <stdio.h>
#include <stdlib.h>
#define N 7 //データの数

// define the node
struct node
{
	int value;
	struct node *left;
	struct node *right;
};

// make node
struct node *newNode(int num)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->value = num;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// insert new value
struct node* insert(struct node* node, int num)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(num);

	// Otherwise, recur down the node
	if (num < node->value)
	{
		if (node->left != NULL)
			insert(node->left, num);
		else
			node->left = newNode(num);
	}
	else
	{
		if (node->right != NULL)
			insert(node->right, num);
		else
			node->right = newNode(num);
	}

	// return the node pointer
	return node;
}

// display the node structure
void display_tree(struct node* node)
{
	if (node == NULL)
		return;

	// display node data
	if (node->left != NULL)
		printf("%d(L:%d)\n", node->value, node->left->value);
	if (node->right != NULL)
		printf("%d(R:%d)\n", node->value, node->right->value);
	//printf("\n");
	display_tree(node->left);
	display_tree(node->right);
}

// inorder the values
void inorder(struct node *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->value);
		inorder(root->right);

	}
}

// calculate tree height
int height_node(struct node *node)
{
	if (node == NULL) return 0;
	int a = height_node(node->left);
	int b = height_node(node->right);
	return 1 + (a > b ? a : b);
}

// free memory
void free_tree(struct node* node)
{
	if (node == NULL)
		return;

	//free children of node
	free_tree(node->left);
	free_tree(node->right);

	//free itself
	free(node);
}

int main()
{
	struct node *root = NULL; //make root

	int data[N] = { 19, 11, 33, 7, 17, 26, 40 };//入力するデータ

	//データの挿入
	root = insert(root, data[0]);
	for (int i = 1; i < N; i++) {
		insert(root, data[i]);
	}

	// display tree relationship
	display_tree(root);
	printf("\n");

	// print inoder traversal of the BST
	printf("Inoder the tree \n");

	inorder(root);
	printf("\n");

	// height of tree
	printf("max height = %d\n", height_node(root));

	return 0;
}
/*
高さ　3
     19
    /  \
  11    33
  /\    /\
 7 17  26 40
*/