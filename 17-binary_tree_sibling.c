#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node; or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *s_node;

	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		s_node = node->parent->right;
	else
		s_node = node->parent->left;
	return (s_node);
}
