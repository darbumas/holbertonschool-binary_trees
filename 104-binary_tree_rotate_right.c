#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else
			new_root->parent->right = new_root;
	}

	return (new_root);
}
