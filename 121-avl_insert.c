#include "binary_trees.h"

/**
 * insert - Inserts a new node in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @new_node: pointer to the new node to be inserted
 * Return: pointer to the new node, NULL otherwise
 */
avl_t *insert(avl_t **tree, avl_t *new_node)
{
	avl_t *current, *parent;

	if (!tree || !new_node)
		return (NULL);

	current = *tree;
	parent = NULL;
	while (current)
	{
		parent = current;
		if (new_node->n < current->n)
			current = current->left;
		else if (new_node->n > current->n)
			current = current->right;
		else
			return (NULL);
	}

	new_node->parent = parent;
	if (!parent)
		*tree = new_node;
	else if (new_node->n < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, NULL otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *unbal_node;
	int bal_factor;

	new_node = binary_tree_node(*tree, value);
	if (!new_node)
		return (NULL);
	if (!*tree)
		*tree = new_node;
	else
		insert(tree, new_node);

	unbal_node = new_node;
	while (unbal_node)
	{
		bal_factor = binary_tree_balance(unbal_node);

		if (bal_factor > 1 && value < unbal_node->left->n)
			unbal_node = binary_tree_rotate_right(unbal_node);
		else if (bal_factor > 1 && value > unbal_node->left->n)
		{
			unbal_node->left = binary_tree_rotate_left(unbal_node->left);
			unbal_node = binary_tree_rotate_right(unbal_node);
		}
		else if (bal_factor < -1 && value > unbal_node->right->n)
			unbal_node = binary_tree_rotate_left(unbal_node);
		else if (bal_factor < -1 && value < unbal_node->right->n)
		{
			unbal_node->right = binary_tree_rotate_right(unbal_node->right);
			unbal_node = binary_tree_rotate_left(unbal_node);
		}
		else
			unbal_node = unbal_node->parent;
	}
	return (new_node);
}

