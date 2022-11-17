#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node
 * @value: value to store
 * Return: pointer to the created node; or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root = NULL, *bst;

	if (!tree)
		return (NULL);
	root = calloc(1, sizeof(bst_t));
	if (!root)
		return (NULL);
	root->n = value;
	if (!*tree)
	{
		*tree = root;
		return (root);
	}
	bst = *tree;
	while (1)
	{
		if (value == bst->n)
		{
			free(root);
			return (NULL);
		}
		if (value < bst->n)
		{
			if (!bst->left)
			{
				root->parent = bst;
				return (bst->left = root);
			}
			bst = bst->left;
		} else
		{
			if (!bst->right)
			{
				root->parent = bst;
				return (bst->right = root);
			}
			bst = bst->right;
		}
	}
}
