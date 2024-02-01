#include "binary_trees.h"

/**
 * binary_tree_levelorder - Go through a binary tree using level-order traverse
 * @tree: tree to got through
 * @func: pointer to a function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxLevel;

	if (!tree || !func)
		return;

	maxLevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxLevel; level++)
		BTlevelorder_util(tree, func, level);
}

/**
 * BTlevelorder_util - Recurse using post-order traverse
 * @tree: Binary tree to go through
 * @func: Pointer to a function to call
 * @level: the level of the tree to call
 */
void BTlevelorder_util(
		const binary_tree_t *tree,
		void (*func)(int),
		size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		BTlevelorder_util(tree->left, func, level - 1);
		BTlevelorder_util(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - finds the height of a binary tree
 * @tree: tree to measure
 * Return: height of the tree or 0 if tree is NULL
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
