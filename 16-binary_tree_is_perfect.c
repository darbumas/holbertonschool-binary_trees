#include "binary_trees.h"
#include <stdbool.h>

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

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (size);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;

	return (size);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * NOTE: a perfect binary tree is a binary tree in which all
 * interior nodes have two children and all leaves have the same
 * depth
 * Return: True or False
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size, height;

	if (!tree)
		return (false);
	size = binary_tree_size(tree);
	height = binary_tree_height(tree);
	return (size == (2 << height) - 1);
}
