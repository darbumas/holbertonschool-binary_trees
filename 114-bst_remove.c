#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST to search
 * @value: value to search for
 * Return: pointer to the node containing the value; or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);
		tree = value < tree->n ? tree->left : tree->right;
	}
	return ((bst_t *)tree);
}

/**
 * swap_successor - swaps two nodes in a BST wiht its' first
 * in-order successor
 * @node: first node
 * @succ: second node
 * Return: point to the root node of BST; or NULL
 */

bst_t *swap_successor(bst_t *node, bst_t *succ)
{
	bst_t *root = NULL;
	int child = 0;

	if (node->parent)
		child = node->parent->left == node;
	if (succ->parent && succ->parent != node)
		succ->parent->left = NULL;
	succ->parent = node->parent;
	if (node->parent)
	{
		if (child)
			node->parent->left = succ;
		else
			node->parent->right = succ;
	}
	if (node->left != succ)
	{
		succ->left = node->left;
		node->left->parent = succ;
	}
	if (node->right && node->right != succ)
	{
		succ->right = node->right;
		node->right->parent = succ;
	}
	root = succ;
	while (root->parent)
		root = root->parent;
	free(node);
	return (root);
}

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node of the tree
 * to delete from
 * @value: value to remove
 * NOTE: once value is located, node must be also be
 * removed and freed
 * Return: pointer to new root node; or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int child = 0;
	bst_t *node, *succ;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
	if (!node)
		return (NULL);
	if (node->parent)
		child = node->parent->left == node;
	if (!node->right && !node->left)
	{
		if (!node->parent)
		{
			free(node);
			return (NULL);
		}
		if (child)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		succ = node->parent;
		while (succ->parent)
			succ = succ->parent;
		free(node);
		return (succ);
	}
	if (!node->right)
		return (swap_successor(node, node->left));
	succ = node->right;
	while (succ->left)
		succ = succ->left;
	return (swap_successor(node, succ));
}

