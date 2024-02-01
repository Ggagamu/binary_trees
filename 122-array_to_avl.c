#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements.
 *
 * Return: Pointer to the root node, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *new_tree = NULL;
	size_t m, g;

	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (g = 0; g < m; g++)
		{
			if (array[g] == array[m])
				break;
		}
		if (g == m)
		{
			if (avl_insert(&new_tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (new_tree);
}
