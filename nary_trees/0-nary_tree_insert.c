#include "nary_trees.h"

#include <string.h>

/**
* nary_tree_insert - inserts a node in a N-ary tree
* @parent: pointer to the parent node
* @str: is a string to be stroed in the created node
*
* Return: pointer to the created node, or NULL on failure
*/

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	if (!str)
		return (NULL);

	nary_tree_t *new_node = malloc(sizeof(nary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;
	if (!parent) /* insert when parent is NULL */
	{
		new_node->parent = NULL;
		new_node->content = strdup(str);
		if (!new_node->content)
			goto strdup_err;
		return (new_node);
	}
	/* insert child node for parent */
	new_node->parent = parent;
	new_node->content = strdup(str);
	if (!new_node->content)
		goto strdup_err;
	if (parent->nb_children > 1)
		new_node->next = parent->children;
	parent->children = new_node;
	parent->nb_children += 1;
	return (NULL);

strdup_err:
	free(new_node);
	return (NULL);
}
