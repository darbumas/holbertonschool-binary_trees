#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * bt_height - Computes the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the binary tree, 0 otherwise
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);

	h_left = bt_height(tree->left);
	h_right = bt_height(tree->right);

	return (1 + MAX(h_left, h_right));
}

/**
 * bt_balance - Computes the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: The balance factor of the tree; 0 otherwise
 */
int bt_balance(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (!tree)
		return (0);

	h_left = bt_height(tree->left);
	h_right = bt_height(tree->right);

	return (h_left - h_right);
}

/**
 * is_avl - helper ƒ() that checks if a binary tree is a valid AVL
 * tree recursively
 * @tree: pointer to the root node of the tree
 * @min: miminum allowed value in the tree
 * @max: maximum allowed value in the tree
 * Return: 1 if the tree is AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int bal;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	bal = bt_balance(tree);

	if (bal > 1 || bal < -1)
		return (0);

	return (is_avl(tree->left, min, tree->n - 1) &&
		is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
