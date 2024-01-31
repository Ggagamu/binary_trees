#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child.
 * @parent: pointer to the parent node.
 * @value: value stored in the new node.
 *
 * Return: NULL on failure.
 *         Otherwise; pointer to created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *L_node;
if (parent == NULL)
return (NULL);
L_node = malloc(sizeof(binary_tree_t));
if (L_node == NULL)
return (NULL);
L_node->n = value;
L_node->parent = parent;
L_node->left = parent->left;
L_node->right = NULL;
parent->left = L_node;
if (L_node->left)
L_node->left->parent = L_node;

return (L_node);
}
