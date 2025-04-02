#include "heap.h"

binary_tree_node_t *fetchEndOfHeap(heap_t *heap);

/**
 * heap_insert - inserts a value in a Min Binary Heap
 * @heap: pointer to parent node in heap
 * @data: data to insert into new node
 *
 * Return: the newly created node or NULL on failure
 */

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	if (!heap || !data)
		return (NULL);

	binary_tree_node_t *tmp_node = NULL, *new_node = NULL;

	tmp_node = heap->root;
	if (tmp_node == NULL)
	{
		new_node = binary_tree_node(NULL, data);
		tmp_node = new_node;
		return (new_node);
	}
	tmp_node = fetchEndOfHeap(heap);
}

/**
 * fetchEndOfHeap - fetchs the last node in a binary tree heap
 * @heap: heap_t pointer containing heap root and size
 *
 * Return: last node in heap or NULL on failure
 */

binary_tree_node_t *fetchEndOfHeap(heap_t *heap)
{
	if (heap == NULL || heap->root == NULL)
		return (NULL);
	
	binary_tree_node_t *queue[heap->size], crnt_node;
	int i, qfront = -1, qrear = -1;

	for (i = 0; i < heap->size; i++)
		queue[i] = NULL;
}