#include "binary_trees.h"

/**
 * recursive_avl_build - helper ƒ() recursively builds an AVL tree from sorted
 * array.
 * @array: pointer to the first element of the array
 * @start: index of the first element of the current subarray
 * @end: index of the last element of the current subarray
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *recursive_avl_build(int *array, size_t start, size_t end)
{
	avl_t *root;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = avl_insert(NULL, array[mid]);
	if (!root)
		return (NULL);

	root->left = recursive_avl_build(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = recursive_avl_build(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (recursive_avl_build(array, 0, size - 1));
}
