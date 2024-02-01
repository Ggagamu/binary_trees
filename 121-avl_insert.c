#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance_factor(const binary_tree_t *tree);
avl_t *avl_insert_recurse(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Finds the height of a binary tree.
 * @tree: Pointer to the root node.
 *
 * Return: 0 if NULL, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t L = 0, R = 0;

		L = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		R = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((L > R) ? L : R);
	}
	return (0);
}

/**
 * balance_factor - Finds the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0 if NULL, else balance factor.
 */
int balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recurse - Inputs value into an AVL tree recursively.
 * @tree: Double pointer to the root node.
 * @parent: The parent node.
 * @new: Double pointer to the new node.
 * @value: The value.
 *
 * Return: Pointer to the new root, or NULL on failure.
 */
avl_t *avl_insert_recurse(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int balFactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recurse(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recurse(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balFactor = balance_factor(*tree);
	if (balFactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balFactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balFactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balFactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recurse(tree, *tree, &new, value);
	return (new);
}
