#include "heap.h"

#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

void rec_heapify(binary_tree_node_t *, int (*)(void *, void *));

/**
 * heap_extract - extract node from the heap
 * @heap: pointer to the heap from which to extract data from
 *
 * Return: data that was stored at root of heap
 */

void *heap_extract(heap_t *heap)
{
	void *extracted_data = NULL;

	if (!heap || !heap->root)
		return (NULL);

	binary_tree_node_t *last_node = NULL, *root_node = NULL;

	root_node = heap->root;
	last_node = breadth_search(heap, LAST_NODE_INSERTED);

	extracted_data = root_node->data;
	root_node->data = last_node->data;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		return (NULL);
	free(last_node);
	rec_heapify(heap->root, heap->data_cmp);
	heap->size--;
	return (extracted_data);
}

/**
 * rec_heapify - update heap to be min heap
 * @node: heap to heapify
 * @data_cmp: function pointer that compares data in two pointers
 *
 * Return: n/a
 */

void rec_heapify(binary_tree_node_t *node, int (*data_cmp)(void *, void *))
{
	if (!node)
		return;

	binary_tree_node_t *tmp_node = NULL;
	void *tmp_data = NULL;
	int ldiff = 0, rdiff = 0;

	if (node->left)
		ldiff = data_cmp(node->data, node->left->data);
	if (node->right)
		rdiff = data_cmp(node->data, node->right->data);

	if (ldiff > 0 || rdiff > 0)
	{
		tmp_node = (ldiff > rdiff) ? node->left : node->right;
		tmp_data = node->data;
		node->data = tmp_node->data;
		tmp_node->data = tmp_data;
	}
	rec_heapify(tmp_node, data_cmp);
}
