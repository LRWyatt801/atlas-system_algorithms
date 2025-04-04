#include "heap/heap.h"
#include "huffman.h"

/**
 * freq_cmp - compares the frequency
 * @p1: first frequency
 * @p2: second frequency
 *
 * Return: difference between frequencies
 */

int freq_cmp(void *p1, void *p2)
{
	binary_tree_node_t *node;
	symbol_t *s1, *s2;

	node = (binary_tree_node_t *)p1;
	s1 = (symbol_t *)node->data;
	node = (binary_tree_node_t *)p2;
	s2 = (symbol_t *)node->data;

	return (s1->freq - s2->freq);
}

/**
* huffman_priority_queue - creates a priority queue
* @data: an array of characters
* @freq: an array of frequency of corresponding characters
* @size: size of arrays
*
* Return: pointer to the created min heap
*/

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	if (!data || !freq)
		return (NULL);

	heap_t *heap = NULL;
	binary_tree_node_t *new_node = NULL;
	symbol_t *new_symbol = NULL;
	size_t i;

	heap = heap_create(freq_cmp);

	for (i = 0; i < size; i++)
	{
		new_symbol = symbol_create(data[i], freq[i]);
		new_node = binary_tree_node(NULL, new_symbol);
		if (!new_node)
			goto cleanup;
		heap_insert(heap, new_node);
	}
	return (heap);

cleanup:
	heap_delete(heap, NULL);
	return (NULL);
}
