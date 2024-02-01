#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree right-wise
 * @tree: a pointer to the root node of the tree
 *
 * Return: Pointer to the new root node of the tree after rotation
 *         NULL on failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);
	old_root = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		old_root->left = tree->right;
		tree->right->parent = old_root;
	}
	else
		old_root->left = NULL;
	old_root->parent = tree;
	tree->right = old_root;
	if (parent)
		parent->left = tree;
	tree->parent = parent;
	return (tree);
}
