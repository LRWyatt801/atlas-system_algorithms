#include "graphs.h"

int is_empty(int);
void enqueue(vertex_t *[], int *, int *, vertex_t *);
vertex_t *dequeue(vertex_t *[], int *, int *);

/**
 * breadth_first_traverse - traverses a graph using the breadth-first algorithm
 * @graph: graph to be traversed
 * @action: callback function pointer to perform on each vertex
 *
 * Return: largest vertex depth, otherwise 0 on failure
 */

size_t breadth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *queue[graph->nb_vertices], *tmp_vertex = graph->vertices;
	int visited[graph->nb_vertices], qfront = -1, qrear = -1;
	edge_t *tmp_edge = tmp_vertex->edges;
	size_t i, depth, same_level, next_level;

	if (!graph || !action || !graph->vertices)
		return (0);
	for (i = 0; i < graph->nb_vertices; i++) /* set queue and visited lists*/
	{
		queue[i] = NULL;
		visited[i] = 0;
	}
	depth = next_level = 0;
	same_level = 1;
	visited[tmp_vertex->index] = 1;
	enqueue(queue, &qfront, &qrear, tmp_vertex);
	while (!is_empty(qrear))
	{
		tmp_vertex = dequeue(queue, &qfront, &qrear);
		action(tmp_vertex, depth);
		tmp_edge = tmp_vertex->edges;
		while (tmp_edge)
		{
			if (!visited[tmp_edge->dest->index])
			{
				enqueue(queue, &qfront, &qrear, tmp_edge->dest);
				visited[tmp_edge->dest->index] = 1;
				next_level++;
			}
			tmp_edge = tmp_edge->next;
		}
		same_level--;
		if (same_level == 0 && next_level > 0)
		{
			depth++;
			same_level = next_level;
			next_level = 0;
		}
	}
	return (depth);
}

/**
 * is_empty - checks if a queue is empty
 * @qrear: check for -1 meaning it is empty
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
 * enqueue - adds a graph vertex to the end of a queue
 * @queue: queue to add to
 * @qfront: front of queue
 * @qrear: end of queue
 * @vertex: vertex pointer to add to queue
 *
 * Return: n/a
 */

void enqueue(vertex_t *queue[], int *qfront, int *qrear, vertex_t *vertex)
{
	if (*qfront == -1)
		*qfront = 0;
	*qrear += 1;
	queue[*qrear] = vertex;
}

/**
 * dequeue - removes a vertex from the queue
 * @queue: queue to remove a vertex from
 * @qfront: front of the queue
 * @qrear: end of the queue
 *
 * Return: pointer to the queued vertex
 */

vertex_t *dequeue(vertex_t *queue[], int *qfront, int *qrear)
{
	vertex_t *tmp_vertex = NULL;

	tmp_vertex = queue[*qfront];
	*qfront += 1;
	if (*qfront > *qrear)
		*qfront = *qrear = -1;

	return (tmp_vertex);
}
