#include "binary_trees.h"

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove from the tree
 * Return: pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
	if (!root->left || !root->right)
	{
		temp = root->left ? root->left : root->right;
		*root = *temp;
		free(temp);
	}
	else
	{
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
}

	if (!root)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
