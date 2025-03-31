#include "heap.h"

#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node of node to be created
 * @data: data to be stored in node
 *
 * Return: Pointer to the created node or NULL on failure
 */

binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	if (!data)
		return (NULL);

	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;


	return (new_node);
}
