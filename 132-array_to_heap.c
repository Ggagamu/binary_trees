#include "binary_trees.h"

/**
 * binary_tree_is_heap - Determines if tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is valid Max Binary Heap
 *         0 if tree is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (BTisheap_util(tree));
}

/**
 * BTisheap_util - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if either tree is a valid Max Binary Heap or NULL
 *         0 otherwise
 */
int BTisheap_util(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (BTisheap_util(tree->left) &&
		BTisheap_util(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
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
 * BTiscomplete_util - If a binary tree is complete
 * @tree: Pointer to the root node
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
 * binary_tree_size - Finds the size of a binary tree
 * @tree: tree to measure
 *
 * Return: size of tree
 *         0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
