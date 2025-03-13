#ifndef RB_TREES_H
#define RB_TREES_H

/***** STRUCTS *****/

/**
* enum rb_color_e - Possible color of a Red-Black tree
*
* @RED: 0 -> Red node
* @BLACK: 1 -> Black node
* @DOUBLE_BLACK: 2 ->
*/
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
* struct rb_tree_s - Red-Black tree node structure
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
* @color: Color of the node (RED or BLACK)
*/
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

/**
 * struct rb_tree_props_s - values used to indicate verification of a rb tree
 * @bst_prev_val: previous value in tree
 * @expt_blk_cnt: count of expected blk nodes
 * @crnt_blk_cnt: current number of blk nodes
 */

typedef struct rb_tree_props_s
{
	int bst_prev_val;
	int expt_blk_cnt;
	int crnt_blk_cnt;
} rb_tree_props_t;

/***** PROTOTYPES *****/

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);

#endif /* RB_TREES_H */
