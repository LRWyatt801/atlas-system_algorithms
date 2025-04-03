#include "heap.h"

#include <stdlib.h>

void rec_delete(binary_tree_node_t *, void (*)(void *));

/**
 * heap_delete - deletes an entire heap
 * @heap: heap to be deleted
 * @free_data: frees data in a node
 *
 * Return: n/a
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap || !heap->root)
		return;

	rec_delete(heap->root, free_data);
	free(heap);
}

/**
 * rec_delete - recursivley delete a heap
 * @node: node to be deleted
 * @free_data: function pointer that will free the data within a node
 *
 * Return: n/a
 */

void rec_delete(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;
	rec_delete(node->left, free_data);
	rec_delete(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}
