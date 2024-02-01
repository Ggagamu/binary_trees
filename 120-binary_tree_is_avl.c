#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if tree is AVL
 * @tree: pointer to the root tree
 *
 * Return: 1 if tree is AVL 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (BTisBST_util(tree, INT_MIN, INT_MAX));
}

/**
 * BTisBST_util - finds if a binary tree is an avl
 * @tree: Pointer to the root node
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl, 0 if not
 */
int BTisBST_util(const binary_tree_t *tree, int min, int max)
{
	int l, r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(l - r) > 1)
		return (0);

	return (BTisBST_util(tree->left, min, tree->n - 1) &&
		BTisBST_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Finds the height of a binary tree
 * @tree: tree to measure
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hLeft = 0;
	size_t hRight = 0;

	if (!tree)
		return (0);

	hLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (hLeft > hRight ? hLeft : hRight);
}
