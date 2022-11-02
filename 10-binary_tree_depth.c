#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth from node ptr; otherwise 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (d);

	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}
