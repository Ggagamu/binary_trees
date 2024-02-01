#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_tree = NULL;
	size_t midpoint;

	if (!array)
		return (NULL);
	midpoint = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[midpoint]);

	SATA_util(&new_tree, array, -1, midpoint);
	SATA_util(&new_tree, array, midpoint, size);

	return (new_tree);
}

/**
 * SATA_util - Creates an AVL tree from an array
 * @root: Double pointer to the root node
 * @array: a pointer to the first element
 * @lo: lower index
 * @hi: upper index
 */
void SATA_util(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new_tree = NULL;
	size_t midpoint;

	if (hi - lo > 1)
	{
		midpoint = (hi - lo) / 2 + lo;
		new_tree = binary_tree_node(*root, array[midpoint]);
		if (array[midpoint] > (*root)->n)
			(*root)->right = new_tree;
		else if (array[midpoint] < (*root)->n)
			(*root)->left = new_tree;
		SATA_util(&new, array, lo, midpoint);
		SATA_util(&new, array, midpoint, hi);
	}
}
