#include "heap/heap.h"
#include "huffman.h"

#include <stdlib.h>

/**
* huffman_extract_and_insert - extracts two nodes and inserts a new one
*	containing the sum freq and the extracted nodes as it leafs/children
* @priority_queue: pointer to priority queue to extract from
*
* Return: 1 on success, 0 on failure
*/

int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *sum_node = NULL, /* node to store sum of freq */
			   *left_node = NULL, /* first node extracted */
			   *right_node = NULL; /* second node extracted */
	symbol_t *sum_sym = NULL; /* symbole to store sum data */

	if (!priority_queue || !priority_queue->root)
		return (0);

	/* extract two nodes */
	left_node = (binary_tree_node_t *)heap_extract(priority_queue);
	right_node = (binary_tree_node_t *)heap_extract(priority_queue);

	/* create sum_node */
	sum_sym = symbol_create((char)-1,
			 ((symbol_t *)left_node->data)->freq +
			 ((symbol_t *)right_node->data)->freq);
	sum_node = binary_tree_node(NULL, sum_sym);
	if (!sum_sym || !sum_node)
	{
		free(sum_sym);
		return (0);
	}

	sum_node->left = left_node;
	sum_node->right = right_node;
	left_node->parent = sum_node;
	right_node->parent = sum_node;

	heap_insert(priority_queue, sum_node);
	return (1);
}
