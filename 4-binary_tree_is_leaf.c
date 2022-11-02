#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf (no children nodes)
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf; otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int ret;

	if (!node)
		return (false);

	ret = !node->left && !node->right;
	return (ret);
}
