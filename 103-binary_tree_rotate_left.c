#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree left-wise
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the new root node of the tree after rotation
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	old_root = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		old_root->right = tree->left;
		tree->left->parent = old_root;
	}
	else
		old_root->right = NULL;
	old_root->parent = tree;
	tree->left = old_root;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
