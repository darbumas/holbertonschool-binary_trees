#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *node_f = (binary_tree_t *)first;
	binary_tree_t *node_s = (binary_tree_t *)second;
	size_t depth_f, depth_s;

	if (!first || !second)
		return (NULL);

	depth_f = binary_tree_depth(first);
	depth_s = binary_tree_depth(second);

	while (depth_s > depth_f)
		node_s = node_s->parent, depth_s--;
	while (depth_f > depth_s)
		node_f = node_f->parent, depth_s--;
	while (node_f && node_s)
	{
		if (node_f == node_s)
			return (node_f);
		node_f = node_f->parent;
		node_s = node_s->parent;
	}
	return (NULL);
}

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
