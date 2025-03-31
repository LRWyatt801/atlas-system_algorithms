#include "heap.h"

#include <stdlib.h>

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	if (!data_cmp)
		return (NULL);

	heap_t *new_heap = malloc(sizeof(heap_t));
	if (!new_heap)
		return (NULL);

	new_heap->root = NULL;
	new_heap->size = 0;
	new_heap->data_cmp = data_cmp;

	return (new_heap);
}
