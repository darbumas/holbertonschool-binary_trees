#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, NULL otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *unbal_node;
	int bal_factor;

	/* Insert value into BST */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}
	/*
	 * If the value to insert is less than the value of the current node,
	 * move to left subtree
	 */
	else if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);
			node = (*tree)->left;
		}
		else
			node = avl_insert(&((*tree)->left), value);
	}
	/*
	 * If the value to insert is greater than the value of the current node
	 * move to the right subtree
	 */
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if (!(*tree)->right)
				return (NULL);
			node = (*tree)->right;
		}
		else
			node = avl_insert(&((*tree)->right), value);
	}
	else
		return (NULL);

	/*
	 * Update height and balance factor of ancestors; starting from the
	 * newly inserted node
	 */
	unbal_node = node;
	while (unbal_node)
	{
		bal_factor = binary_tree_balance(unbal_node);

		if (bal_factor > 1 && value < unbal_node->left->n)
			unbal_node = binary_tree_rotate_right(unbal_node);

		else if (bal_factor < -1 && value > unbal_node->right->n)
			unbal_node = binary_tree_rotate_left(unbal_node);

		else if (bal_factor > 1 && value > unbal_node->left->n)
		{
			unbal_node->left = binary_tree_rotate_left(
						unbal_node->left);
			unbal_node = binary_tree_rotate_right(
					unbal_node);
		}
		else if (bal_factor < -1 && value < unbal_node->right->n)
		{
			unbal_node->right = binary_tree_rotate_right(
						unbal_node->right);
			unbal_node = binary_tree_rotate_left(unbal_node);
		}
		else
			unbal_node = unbal_node->parent;
	}
	return (node);
}
