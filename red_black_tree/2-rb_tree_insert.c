#include "rb_trees.h"
#include <stdio.h>

#define LL 1 /* 0000 0001 */
#define RR 2 /* 0000 0010 */
#define LR 4 /* 0000 0100 */
#define RL 8 /* 0000 1000 */

static rb_tree_t *rotateLeft(rb_tree_t *);
static rb_tree_t *rotateRight(rb_tree_t *);
static rb_tree_t *orderedInsert(rb_tree_t *, int);
static void redRedHandler(rb_tree_t *);
static rb_tree_t *rotator(rb_tree_t *, int);

void rb_tree_print(const rb_tree_t *tree);

/**
* rb_tree_insert - inserts a value in a Red-Black tree
* @tree: root of Red-Black tree to insert value into
* @value: value to insert
*
* Return: pointer to newly created node, otherwise NULL
*/

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node;

	if (!*tree)
		return (*tree = rb_tree_node(NULL, value, BLACK));
	else
	{
		new_node = orderedInsert(*tree, value);

		(*tree)->color = BLACK;
	
		return (new_node);
	}
}

/**
 * rotateLeft - Rotates a node to the left.
 * @node: Pointer to the node to be rotated.
 *
 * Return: The new root of the rotated subtree.
 */
static rb_tree_t *rotateLeft(rb_tree_t *tree)
{
	printf("rotate Left\n");
	rb_tree_t *x = tree->right;
	rb_tree_t *y = x->left;

	x->left = tree;
	tree->right = y;

	if (y)
		y->parent = tree;

	x->parent = tree->parent;
	tree->parent = x;

	if (x->parent) {
		if (x->parent->left == tree)
			x->parent->left = x;
		else
			x->parent->right = x;
	}

	return x;
}

/**
 * rotateRight - Rotates a node to the right.
 * @node: Pointer to the node to be rotated.
 *
 * Return: The new root of the rotated subtree.
 */
static rb_tree_t *rotateRight(rb_tree_t *node)
{
    printf("rotate Right\n");
    rb_tree_t *x = node->left;

    if (!x)  // Prevent rotation if there's no left child
        return node;

    rb_tree_t *y = x->right;

    x->right = node;
    node->left = y;

    if (y)
        y->parent = node;

    x->parent = node->parent;
    node->parent = x;

    // Update the parent's child pointer if necessary
    if (x->parent) {
        if (x->parent->left == node)
            x->parent->left = x;
        else
            x->parent->right = x;
    }

    return x;
}

/**
* orderedInsert - insert a node in value order
* @tree: tree to insert to
* @value: value of node to insert
*
* Return: newly created node
*/

static rb_tree_t *orderedInsert(rb_tree_t *tree, int value)
{
	if (!tree)
		return (rb_tree_node(NULL, value, RED));
	else if (value < tree->n)
	{
		tree->left = orderedInsert(tree->left, value);
		tree->left->parent = tree;
		if (tree->parent != NULL)
		{
			if (tree->color == RED && tree->left->color == RED)
				redRedHandler(tree);
		}
	}	
	else if (value > tree->n)
	{
		tree->right = orderedInsert(tree->right, value);
		tree->right->parent = tree;
		if (tree->parent != NULL)
		{
			if (tree->color == RED && tree->right->color == RED)
				redRedHandler(tree);
		}
	}
	return (tree);
}

/**
* redRedHandler - handle red-red conflicts
* @tree: node of a tree where conflict is
*
* Return: n/a
*/

static void redRedHandler(rb_tree_t *tree)
{
    if (tree == NULL || tree->parent == NULL)
        return;

    printf("redhandler\n");
    
    /* if tree is parents right */
    if (tree->parent->right == tree)
    {
        /* perform needed rotations */
        if (tree->parent->left == NULL || tree->parent->left->color == BLACK)
        {
            if (tree->left && tree->left->color == RED)
                printf("RL\n");
            else if (tree->right && tree->right->color == RED)
				rotator(tree->parent, RR);
				printf("node: %d\n", tree->n);
        }
        else if (tree->parent->left) /* recolor */
        {
            tree->parent->left->color = BLACK;
            tree->color = BLACK;
            if (tree->parent->parent)
                tree->parent->color = RED;
        }
    }
    else /* tree is parent's left child */
    {
        if (tree->parent->right == NULL || tree->parent->right->color == BLACK)
        {
            if (tree->left && tree->left->color == RED)
                printf("LR\n");
            else if (tree->right && tree->right->color == RED)
                printf("LL\n");
        }
        else if (tree->parent->right)
        {
            tree->parent->right->color = BLACK;
            tree->color = BLACK;
            if (tree->parent->parent)
                tree->parent->color = RED;
        }
    }
}

/**
* rotator - rotates a tree
* @tree: node of a tree
* @rotate_case: case of ratate
*
* Return: n/a
*/

static rb_tree_t *rotator(rb_tree_t *tree, int rotate_case)
{
	printf("rotator\n");
	switch (rotate_case)
	{
		case LL:
			tree = rotateRight(tree);
			tree->color = BLACK;
			tree->right->color = RED;
			return (tree);
		case RR:
			tree = rotateLeft(tree);
			tree->color = BLACK;
			tree->left->color = RED;
			rb_tree_print(tree);
			return (tree);
		case RL:
			tree->right = rotateRight(tree->right);
			tree->right->parent = tree;
			tree = rotateLeft(tree);
			tree->color = BLACK;
			tree->left->color = RED;
			return (tree);
		case LR:
			tree->left = rotateLeft(tree->left);
			tree->left->parent = tree;
			tree = rotateRight(tree);
			tree->color = BLACK;
			tree->right->color = RED;
			return (tree);
	}
	return (tree);
}
