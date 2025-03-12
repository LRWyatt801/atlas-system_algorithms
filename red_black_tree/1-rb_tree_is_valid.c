#include "rb_trees.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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
	rb_tree_props_t verifiers;
	if (!tree)
		return (FALSE);

	if (tree->color != BLACK) /* verify property #3 */
		return (FALSE);

	/* set verifiers to true */
	verifiers.is_bst = verifiers.is_red_or_blk = verifiers.root_is_blk =
		verifiers.no_adj_reds = verifiers.same_num_of_blk = TRUE;

	/* set blk_cnt to -1 for future use */
	verifiers.expt_blk_cnt = verifiers.bst_prev_val = -1;

	tree_traversal(&verifiers, tree);

	if (!verifiers.is_bst || !verifiers.is_red_or_blk ||
		!verifiers.root_is_blk || !verifiers.no_adj_reds ||
		!verifiers.same_num_of_blk)
		return (FALSE);

	return (TRUE);
}

/**
* tree_traversal - traverses a binary tree to perfoming different checks
*		   to validate if it is a Red Black Tree
* @verifiers: a struct holding different check values to verify tree
* @tree: node of tree
*
* Return: n/a
*/

void tree_traversal(rb_tree_props_t *verifiers, const rb_tree_t *tree)
{
	if (!tree)
	{
		verifiers->crnt_blk_cnt++;
		if (verifiers->expt_blk_cnt == -1)
			verifiers->expt_blk_cnt = verifiers->crnt_blk_cnt;
		/* check for property #5 */
		else if (verifiers->crnt_blk_cnt != verifiers->expt_blk_cnt)
		{
			printf("blk cnt error\n");
			verifiers->same_num_of_blk = FALSE;
			return;
		}
		return;
	}
	if (tree->color == BLACK)
		verifiers->crnt_blk_cnt++;

	/* check for property #2 */
	if (tree->color != RED || tree->color != BLACK)
	{
		printf("color error\n");
		verifiers->is_red_or_blk = FALSE;
		return;
	}

	/* check for property #4 */
	if (tree->color == RED)
	{
		if (tree->parent->color == RED || tree->left->color == RED ||
			tree->right->color == RED)
		{
			printf("adj red error\n");
			verifiers->no_adj_reds = FALSE;
			return;
		}
	}

	tree_traversal(verifiers, tree->left);

	/* check for property #1 */
	if (verifiers->bst_prev_val == -1 || verifiers->bst_prev_val < tree->n)
		verifiers->bst_prev_val = tree->n;
	else
	{
		printf("bst error\n");
		verifiers->is_bst = FALSE;
		return;
	}

	tree_traversal(verifiers, tree->right);
}
