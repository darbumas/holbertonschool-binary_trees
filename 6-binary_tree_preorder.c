#include "binary_trees.h"

/**
 * binary_tree_preorder - visits binary tree in pre-order traversal method
 * @tree: pointer to the root node
 * @func: pointer to a function to call ffor each node
 * NOTE: value in the node must be passed as a parameter to this function
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func && tree)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
