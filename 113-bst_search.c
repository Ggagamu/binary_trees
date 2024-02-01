#include "binary_trees.h"

/**
 * bst_search - Looks for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST
 * @value: the value to search
 * Return: A pointer to the node
 *         NULL if either tree is NULL or no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *new_node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (new_node)
	{
		if (value == new_node->n)
			return (new_node);
		if (value < new_node->n)
			new_node = new_node->left;
		else if (value > new_node->n)
			new_node = new_node->right;
	}

	return (NULL);
}
