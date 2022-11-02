#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * in a binary tree
 * @tree: pointer to the root node of the tree
 * NOTE: a NULL pointer will not be considered a node.
 * Return: the count of nodes with at least 1 child; otherwise 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);

	if (tree->left || tree->right)
	{
		count = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1;
		return (count);
	}
return (count);
}
