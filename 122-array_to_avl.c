#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, NULL otherwise
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}
	return (tree);
}
