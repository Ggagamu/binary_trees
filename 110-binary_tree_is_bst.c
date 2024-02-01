#include "binary_trees.h"

/**
 * binary_tree_is_bst - Finds out if binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (BTisBST_util(tree, INT_MIN, INT_MAX));
}

/**
 * BTisBST_util - check if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum checked nodes
 * @max: Maximum checked nodes
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int BTisBST_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (BTisBST_util(tree->left, min, tree->n - 1) &&
		BTisBST_util(tree->right, tree->n + 1, max));
}
