#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointerr to the root node; or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array)
		return (root);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
