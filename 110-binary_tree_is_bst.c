#include "binary_trees.h"

/**
 * is_valid_bst - helper func for recursive traversal
 * @tree: pointer to the root node of the tree
 * @min: min value of BST
 * @max: max value of BST
 * Return: 1 if tree is BST; 0 otherwise
 */
int is_valid_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_valid_bst(tree->left, min, tree->n - 1) &&
		is_valid_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST; 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
