#include "binary_trees.h"

bst_t *loop_util(bst_t *root);
bst_t *bst_del(bst_t *root, bst_t *node);
bst_t *bst_node_remover(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * loop_util - LOops throught a binary search tree.
 * @root: A pointer to the root node of the BST.
 *
 * Return: Pointer to in-order suc.
 */
bst_t *loop_util(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_del - Delete node from a binary search tree.
 * @root: Pointer to the root node.
 * @node: Pointer to the node to delete.
 *
 * Return: Pointer to the new root node.
 */
bst_t *bst_del(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *heir = NULL;

	/* Right-child */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/*  Left and Right */
	heir = loop_util(node->right);
	node->n = heir->n;

	return (bst_del(root, heir));
}

/**
 * bst_node_remover - Remove a node from a binary search tree.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the current node.
 * @value: The value to remove.
 *
 * Return: Pointer to the root node.
 */
bst_t *bst_node_remover(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Pointer to the root node of the BST.
 * @value: The value to remove.
 *
 * Return: Pointer to the new root node.
 *
 * Description: BTS - Remove.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_node_remover(root, root, value));
}
