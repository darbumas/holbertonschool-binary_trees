#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_is_full - checksd if a binary tree is full
 * @tree: pointer to the root node of the tree
 * NOTE: a full binary tree is a tree in which every node
 * has either 0 or 2 children nodes (a single vertex).
 * Return: True or False
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (false);

	if (!tree->left && !tree->right)
		return (true);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
