#include "nary_trees.h"

/**
* nary_tree_delete - deallocates a nary tree from memory
* @tree: pointer to tree
*
* Return: n/a
*/

void nary_tree_delete(nary_tree_t *tree)
{
	if (!tree)
		return;

	nary_tree_t *child, *next;

	child = tree->children;
	while (child != NULL)
	{
		next = child->next;
		nary_tree_delete(child);
		child = next;
	}
	free(tree->content);
	free(tree);
}
