#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * NOTE: leaf is a node which does not have any child node
 * Return: count of leaves found; otherwise 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);

	if (!tree->left && !tree->right)
		return (true); /* same as 1 */

	count = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (count);
}
