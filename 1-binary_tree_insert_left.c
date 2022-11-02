#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * NOTE: if parent already has a left-child, the new node takes its place,
 * and the old left-child is set as the left-child of the new node.
 * Return: pointer to the newly created node; or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);

	node = calloc(1, sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->n = value;
	if (parent->left)
	{
		node->left =  parent->left;
		node->left->parent = node;
	}
	parent->left = node;
	return (node);
}

