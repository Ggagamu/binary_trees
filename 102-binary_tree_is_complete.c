#include "binary_trees.h"

/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete
 *         0 if tree is either incomplete or NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (BTiscomplete_util(tree, 0, size));
}

/**
 * BTiscomplete_util - Finds if binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: node index
 * @size: number of nodes
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is incomplete or NULL
 */
int BTiscomplete_util(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (BTiscomplete_util(tree->left, 2 * index + 1, size) &&
		BTiscomplete_util(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - finds the size of a binary tree
 * @tree: tree to measure
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
