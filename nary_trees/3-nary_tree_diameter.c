#include "nary_trees.h"
#include <stddef.h>

size_t nary_tree_rec(nary_tree_t const *node, size_t *diameter);

/**
* nary_tree_diameter - finds the diameter of a nary tree
* @root: root of tree
*
* Return: diameter of tree
*/

size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	if (!root)
		return (0);
	nary_tree_rec(root, &diameter);
	return (diameter + 1);
}

/**
* nary_tree_rec - recursively traverse nary tree
* @node: current node of tree
* @diameter: current diameter of node
*
* Return: max depth of tree
*/

size_t nary_tree_rec(nary_tree_t const *node, size_t *diameter)
{
	nary_tree_t *child;
	size_t max_1 = 0, max_2 = 0, child_depth = 0;

	if (!node)
		return (0);

	for (child = node->children; child; child = child->next)
	{
		child_depth = nary_tree_rec(child, diameter);
		if (child_depth > max_1)
		{
			max_2 = max_1;
			max_1 = child_depth;
		}
		else if (child_depth > max_2)
			max_2 = child_depth;
	}
	if (max_2 + max_1 > *diameter)
		*diameter = max_1 + max_2;

	return (max_1 + 1);
}
