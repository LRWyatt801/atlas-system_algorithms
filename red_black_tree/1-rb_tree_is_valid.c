#include "rb_trees.h"

/**
* rb_tree_is_valid - verifies the red black validity of a tree
* @tree: a tree to check
*
* Properties of a Red Black tree:
* 1 - The tree must be a binary search tree (ordered)
* 2 - Every node must be either red or black
* 3 - The root of the tree must be black
* 4 - There are no two adjacent red nodes
* 5 - Every path from Root to NULL has the same number of black nodes
*
* Return: 1 if true, 0 if false
*/

int rb_tree_is_valid(const rb_tree_t *tree)
{
	rb_tree_props_t prop_vals;

	if (!tree)
		return (0);
	/* root color check; verify prop #3 */
	if (tree->color != BLACK)
		return (0);


}
