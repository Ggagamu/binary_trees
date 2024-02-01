#include "binary_trees.h"

/**
 * bst_insert - Puts value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST
 * @value: the value to store in the node
 * Return: A pointer to the new node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *old_root = NULL;
	bst_t *second = NULL;
	bst_t *new_root = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	old_root = *tree;
	while (old_root)
	{
		second = old_root;
		if (value < old_root->n)
			old_root = old_root->left;
		else if (value > old_root->n)
			old_root = old_root->right;
		else if (value == old_root->n)
			return (NULL);
	}

	new_root = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new_root;
	else if (value < second->n)
	{
		second->left = new_root;
		new_root->parent = second;
	}
	else
	{
		second->right = newr_root;
		new_root->parent = second;
	}

	return (new_root);
}
