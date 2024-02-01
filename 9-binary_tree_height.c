#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of binary tree
 * @tree: the binary tree
 *
 * Return: height of the tree
 *         0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t hRight = 0, hLeft = 0;

		hLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		hRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((hLeft > hRight) ? hLeft : hRight);
	}
	return (0);
}
