#include "binary_trees.h"

/**
 * bt_height - computes the height of binary tree
 * @tree: pointer to the root node of the tree
 * Return: the height, 0 otherwise
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((l_height > r_height) ? l_height : r_height);
}

/**
 * bt_balance - Computes the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: The balance factor of the tree; 0 otherwise
 */
int bt_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? bt_height(tree->left) - bt_height(tree->right)
			: 0);
}

/**
 * recursive_insert - helper ƒ() to insert value into an AVL tree
 * recursively
 * @tree: double pointer to the root node of the AVL tree
 * @parent: pointer to the parent node of the current node
 * @new: double pointer to store the new node
 * @value: the value to insert into the AVL tree
 * Return: pointer to the new root; NULL otherwise
 */
avl_t *recursive_insert(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bal;

	if (!*tree)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = recursive_insert(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = recursive_insert(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal = bt_balance(*tree);
	if (bal > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bal < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bal > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: double pointer to the root of the AVL tree
 * @value: value to store in the node inserted
 * Return: pointer to the created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	recursive_insert(tree, *tree, &node, value);
	return (node);
}
