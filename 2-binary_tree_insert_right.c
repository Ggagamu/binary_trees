#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * @parent: pointer to the parent.
 * @value: value to store in the right-child.
 * Return: NULL on failure.
 *         Otherwise - a pointer to the new node.
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *R_node;

	if (parent == NULL)
		return (NULL);
	R_node = malloc(sizeof(binary_tree_t));
	if (R_node == NULL)
		return (NULL);
	R_node->n = value;
	R_node->parent = parent;
	R_node->left = NULL;
	R_node->right = parent->right;
	parent->right = R_node;
	if (R_node->right)
		R_node->right->parent = R_node;

	return (R_node);
}
