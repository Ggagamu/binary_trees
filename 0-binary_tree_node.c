#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the new node.
 * @value: The value.
 *
 * Return: Pointer to a new node.
 *         Otherwise, NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *N_node;

	N_node = malloc(sizeof(binary_tree_t));
	if (N_node == NULL)
		return (NULL);

	N_node->n = value;
	N_node->parent = parent;
	N_node->left = NULL;
	N_node->right = NULL;

	return (N_node);
}
