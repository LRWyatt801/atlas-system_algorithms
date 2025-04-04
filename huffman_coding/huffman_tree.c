#include "heap/heap.h"
#include "huffman.h"

/**
* huffman_tree - builds a huffmantree
* @data: an array of characters
* @freq: an array containing the associated frequencies
* @size: size of arrays
*
* Return: root node of the huffman tree, or NULL on failure
*/

binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	if (!data || !freq || size <= 0)
		return (NULL);

	heap_t *priority_queue = NULL;
	binary_tree_node_t *huff_root = NULL;

	priority_queue = huffman_priority_queue(data, freq, size);
	if (!priority_queue)
	{
		perror("huffman_tree: create queue fail\n");
		return (NULL);
	}

	/* extract */
	while (priority_queue->size > 1)
	{
		if (!huffman_extract_and_insert(priority_queue))
			return (NULL);
	}

	huff_root = heap_extract(priority_queue);
	heap_delete(priority_queue, NULL);

	return (huff_root);
}
