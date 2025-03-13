#include "rb_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
* rb_tree_node - creates a new node for a red black tree
* @parent: parent node of new node to be created
* @value: value of new node
* @color: color of new node
*
* Return: rb_tree_t node on success, otherwise NULL
*/

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node;

	new_node = malloc(sizeof(rb_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->color = color;
	new_node->left = new_node->right = NULL;

	return (new_node);
}

