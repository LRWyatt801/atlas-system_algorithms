#include "heap.h"

binary_tree_node_t *breadth_search(heap_t *, int);
int is_empty(int);
void enqueue(binary_tree_node_t *[], int *, int *, binary_tree_node_t *);
binary_tree_node_t *dequeue(binary_tree_node_t *[], int *, int *);
void heapify(heap_t *, binary_tree_node_t *);

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

	new_node = binary_tree_node(NULL, data);
	if (!heap->root)
	{
		heap->size += 1;
		heap->root = new_node;
		return (new_node);
	}
	tmp_node = breadth_search(heap, NXT_OPEN_Q_NODE);
	new_node->parent = tmp_node;
	if (!tmp_node->left)
	{
		tmp_node->left = new_node;
		heapify(heap, tmp_node->left);
	}
	else
	{
		tmp_node->right = new_node;
		heapify(heap, tmp_node->right);
	}
	heap->size += 1;
	return (new_node);
}

/**
 * fetchEndOfHeap - fetchs the last node in a binary tree heap
 * @heap: heap_t pointer containing heap root and size
 * @last_node: 1 = search for last node inserted, 0 = next open position
 *
 * Return: last node in heap or NULL on failure
 */

binary_tree_node_t *breadth_search(heap_t *heap, int last_node)
{
	if (heap == NULL || heap->root == NULL)
		return (NULL);
	
	binary_tree_node_t *queue[heap->size], *crnt_node;
	int qfront = -1, qrear = -1;
	size_t i;

	for (i = 0; i < heap->size; i++)
		queue[i] = NULL;
	crnt_node = heap->root;
	enqueue(queue, &qfront, &qrear, crnt_node);
	while (!is_empty(qrear))
	{
		crnt_node = dequeue(queue, &qfront, &qrear);
		if (!last_node)
		{
			if (!crnt_node->left || !crnt_node->right)
				return (crnt_node);
		}
		else
		{
			/* TODO make code for last node inserted */
		}
		if (crnt_node->left)
			enqueue(queue, &qfront, &qrear, crnt_node->left);
		if (crnt_node->right)
			enqueue(queue, &qfront, &qrear, crnt_node->right);
	}
	return (crnt_node);
}

/**
 * is_empty - checks if a queue is empty
 * @qrear: check for -1 meaning queue is empty
 *
 * Return: 1 if empty, 0 if not empty
 */

int is_empty(int qrear)
{
	if (qrear == -1)
		return (1);
	return (0);
}

/**
 * enqueue - adds a heap node to the end of queue
 * @queue: queue to add to
 * @qfront: front of queue
 * @qrear: end of queue
 * @node: node to add to queue
 *
 * Return: n/a
 */

void enqueue(binary_tree_node_t *queue[], int *qfront, int *qrear, binary_tree_node_t *node)
{
	if (*qfront == -1)
		*qfront = 0;
	*qrear += 1;
	queue[*qrear] = node;
}

/**
 * dequeue - removes a node from the queue
 * @queue: queue to remove a node from
 * @qfront: front of the queue
 * @qrear: end of the queue
 *
 * Return: pointer to the queued node
 */

binary_tree_node_t *dequeue(binary_tree_node_t *queue[], int *qfront, int *qrear)
{
	binary_tree_node_t *tmp_node = NULL;

	tmp_node = queue[*qfront];
	*qfront += 1;
	if (*qfront > *qrear)
		*qfront = *qrear = -1;

	return (tmp_node);
}

/**
 * heapify - rearrangnes heap to a min heap
 * @heap: heap to rearrange
 *
 * Return: n/a
 */

void heapify(heap_t *heap, binary_tree_node_t *node)
{
	if (!heap || !node->parent)
		return;
	
	void *tmp_data;
	
	while (node->parent && heap->data_cmp(node->parent->data, node->data) > 0)
	{
		tmp_data = node->data;
		node->data = node->parent->data;
		node->parent->data = tmp_data;
		node = node->parent;
	}
}