#include "binary_trees.h"

/**
 * binary_trees_ancestor - Determines the lowest common ancestor of two nodes.
 * @first: Pointer to first node.
 * @second: Pointer to second node.
 *
 * Return: Pointer to the ancestor node otherwise; NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t D_first, D_second;

	if (!first || !second)
		return (NULL);

	D_first = binary_tree_depth(first);
	D_second = binary_tree_depth(second);

	while (D_first > D_second)
	{
		first = first->parent;
		D_first--;
	}
	while (D_second > D_first)
	{
		second = second->parent;
		D_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Determines the depth of a node in a binary tree
 * @tree: node to calculate the depth of.
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t N_depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		N_depth++;
		tree = tree->parent;
	}

	return (N_depth);
}
