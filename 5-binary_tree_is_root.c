#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: pointer to the node to check
 *
 * Return: 1 if node is root; otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int ret;

	if (!node)
		return (false);

	ret = !node->parent;
	return (ret);
}
