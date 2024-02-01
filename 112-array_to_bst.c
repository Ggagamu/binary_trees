#include "binary_trees.h"

/**
 * array_to_bst - creates a Binary Search Tree from an array
 * @array: Pointer to the first element of the array
 * @size: the number of elements
 * Return: A pointer to the root node of the new BST
 *         NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int m;
	bst_t *new_root = NULL;

	for (m = 0; m < size; m++)
		bst_insert(&new_root, array[m]);

	return (new_root);
}
