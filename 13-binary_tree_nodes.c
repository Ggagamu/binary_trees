#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes
 * @tree: Pointer to the root node of the tree
 * Return: Number of nodes in a tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t Nodes = 0;

	if (tree)
	{
		Nodes += (tree->left || tree->right) ? 1 : 0;
		Nodes += binary_tree_nodes(tree->left);
		Nodes += binary_tree_nodes(tree->right);
	}
	return (Nodes);
}
