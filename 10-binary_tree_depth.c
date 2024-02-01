#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of binary tree
 * @tree: the binary tree
 *
 * Return: depth of the tree
 *         0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
