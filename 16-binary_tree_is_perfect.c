#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is either not perfect or NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, nodes = 0, pow = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	pow = (size_t)_pow_recursion(2, height + 1);
	return (pow - 1 == nodes);
}

/**
 *_pow_recursion - raises x to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: The binary tree
 *
 * Return: size
 *         0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - measure height of a binary tree
 * @tree: the binary tree
 *
 * Return: height of the tree
 *         0 if tree is NULL
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
