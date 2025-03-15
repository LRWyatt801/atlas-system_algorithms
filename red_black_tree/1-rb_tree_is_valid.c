#include "rb_trees.h"
#include <stdio.h>

#define ZERO_HGT 0

static int red_checks(const rb_tree_t *);
static int blk_hgt(const rb_tree_t *);
static int is_bst(int, const rb_tree_t *);

/* static int verify_red_adj(const rb_tree_t *tree); */

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
	if (!tree)
		return (0);

	/* root color check; verify prop #3 */
	if (tree->color != BLACK)
		return (0);
	/* property checks for #3 and #4 */
	if (!red_checks(tree))
		return (0);
	/* property check for #5 */
	if (blk_hgt(tree) == -1)
		return (0);
	/*property check for #1 */
	if (is_bst(0, tree) == 0)
		return (0);

	return (1);
}

/**
 * red_checks - performs red black tree property checks on a tree
 * @tree: node of tree
 *
 * Return: 1 if valid tree, 0 otherwise
 */

static int red_checks(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color == RED)
	{
		/* check for adj red nodes */
		if ((tree->parent != NULL && tree->parent->color == RED) ||
		    (tree->left != NULL && tree->left->color == RED) ||
		    (tree->right != NULL && tree->right->color == RED))
			return (0);
	}
	/* verify prop #2 node color */
	else if (tree->color != BLACK && tree->color != RED)
		return (0);

	red_checks(tree->left);
	red_checks(tree->right);

	return (1);
}

/**
* blk_hgt - returns the black height of tree
* @tree: node of tree
*
* Return: black height, or -1 if not matching height
*/

static int blk_hgt(const rb_tree_t *tree)
{
	int l_hgt, r_hgt, crnt_hgt;

	if (tree == NULL)
		return (1);

	l_hgt = blk_hgt(tree->left);
	r_hgt = blk_hgt(tree->right);

	if (l_hgt == -1 || r_hgt == -1)
		return (-1);

	crnt_hgt = (tree->color == BLACK) ? 1 : 0;
	return ((l_hgt == r_hgt) ? l_hgt + crnt_hgt : -1);
}

/**
* is_bst - checks if a tree is a bst (ordered)
* @prev_val: previous value in tree
* @tree: node of tree
*
* Return: 1 if true, otherwise 0
*/

static int is_bst(int prev_val, const rb_tree_t *tree)
{
	if (!tree)
		return (1);


	if (!is_bst(prev_val, tree->left))
		return (0);

	if (prev_val >= tree->n)
		return (0);

	prev_val = tree->n;

	return (is_bst(prev_val, tree->right));
}
