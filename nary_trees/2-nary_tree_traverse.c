#include "nary_trees.h"

#define INIT_DEPTH 0

size_t nary_tree_rec(nary_tree_t const *node, size_t depth,
		     void (*action)(nary_tree_t const *, size_t));


/**
* nary_tree_traverse - traverses a nary tree node by node
* @root: root of tree
* @action: action to perform on each node
*
* Return: depth of tree
*/

size_t nary_tree_traverse(nary_tree_t const *root,
			void (*action)(nary_tree_t const *node, size_t depth))
{
	if (!root || !action)
		return (0);

	return (nary_tree_rec(root, INIT_DEPTH, action));
}

/**
* nary_tree_rec - recursively traverse nary tree
* @node: current node of tree
* @depth: current depth of node
* @action: action to perform on node
*
* Return: max depth of tree
*/

size_t nary_tree_rec(nary_tree_t const *node, size_t depth,
		     void (*action)(nary_tree_t const *, size_t))
{
	nary_tree_t *child;
	size_t max_depth = depth, child_depth = 0;

	if (!node)
		return (depth);

	action(node, depth);
	depth++;

	for (child = node->children; child; child = child->next)
	{
		child_depth = nary_tree_rec(child, depth, action);
		max_depth = (max_depth > child_depth) ?
			     max_depth : child_depth;
	}
	return (max_depth);
}
