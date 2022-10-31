#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	char *data;
	struct node *right;
};

typedef struct node node;


/* This function receives a node of an arithmetic expression tree */
/* and recursively evaluates it */
int evaluateExpressionTree(node *root){
	int left_sum, right_sum;

	/*empty tree*/
	if (root==NULL)
		return 0;

	/*leaf node*/
	if ((root->left==NULL) && (root->right==NULL))
		return atoi(root->data);

	/*evaluate left tree*/
	left_sum = evaluateExpressionTree(root->left);

	/*evaluate right tree*/
	right_sum = evaluateExpressionTree(root->right);

	/*check which operation to apply*/
	if (*(root->data) == '+')
		return left_sum + right_sum;

	else
		if (*(root->data) == '-')
			return left_sum - right_sum;

	else
		if (*(root->data) == '*')
			return left_sum * right_sum;

	else
		return (left_sum / right_sum);
}

/*a main() to test the above code for the arithmetic expression below */
int main(){
	node *root;

	/*creating a sample tree*/
	root = malloc(sizeof(node));
        root->data = "+";
	root->left = malloc(sizeof(node));
	root->left->data = "*";
	root->left->left = malloc(sizeof(node));
	root->left->left->data  = "5";
	root->left->left->left  = NULL;
        root->left->left->right = NULL;
	root->left->right = malloc(sizeof(node));
        root->left->right->data  = "-4";
        root->left->right->left  = NULL;
        root->left->right->right = NULL;
	root->right = malloc(sizeof(node));
	root->right->data = "-";
	root->right->left = malloc(sizeof(node));
	root->right->left->data  = "100";
	root->right->left->left  = NULL;
        root->right->left->right = NULL;
	root->right->right = malloc(sizeof(node));
	root->right->right->data  = "20";
	root->right->right->left  = NULL;
        root->right->right->right = NULL;

	/*solving the corresponding expression*/
	printf("%d\n", evaluateExpressionTree(root));

	return 1;
}
