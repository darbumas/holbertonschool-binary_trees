#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * NOTE: if parent already has a right-child, the new node takes
 * its place, and the old right-child is set as right-child of new node.
 * Return: pointer to the created node; or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = calloc(1, sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->n = value;

	if (parent->right)
	{
		node->right = parent->right;
		node->right->parent = node;
	}
	parent->right = node;
	return (node);
}
