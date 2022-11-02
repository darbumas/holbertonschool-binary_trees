#include "binary_trees.h"

/**
 * is_higher - returns which ever of the two param is bigger
 * @right: first param
 * @left: second param
 * Return: the bigger value
 */
size_t is_higher(size_t left, size_t right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * comp_children_nodes - compares the levels of children nodes
 * @tree: pointer to the root node of the tree
 * Return: the value of the longest path
 */
size_t comp_children_nodes(const binary_tree_t *tree)
{
	size_t left, right, max;

	if (!tree)
		return (0);

	left = comp_children_nodes(tree->left);
	right = comp_children_nodes(tree->right);
	max = is_higher(left, right) + 1;
	return (max);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: levels from node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (comp_children_nodes(tree) - 1);
}
