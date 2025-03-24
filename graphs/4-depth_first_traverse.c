#include "graphs.h"

#define INIT_DEPTH 0

size_t dfsrec(vertex_t *vertex,
			  void (*action)(const vertex_t *v, size_t depth),
			  size_t crnt_depth,
			  size_t visited[]);

/**
 * depth_first_traverse - traverses a graph using depth-first algorithm
 * @graph: pointer to the graph to traverse
 * @action: callback function pointer to perform on each visited vertex
 *
 * Return: biggest vertex depth, or 0 on failure
 */

size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	size_t visited[graph->nb_vertices], i = 0;

	for (i = 0; i < graph->nb_vertices; i++)
		visited[i] = 0;

	return (dfsrec(graph->vertices, action, INIT_DEPTH, visited));
}

/**
 * dfsrec - recursively search graph depth-first
 * @vertex: pointer to current vertex to explore
 * @action: callback function pointer to perfom on each visited vertex
 * @crnt_depth: current depth
 * @visited: array of visited vertices
 *
 * Return: max depth level
 */

size_t dfsrec(vertex_t *vertex,
			  void (*action)(const vertex_t *v, size_t depth),
			  size_t crnt_depth,
			  size_t visited[])
{
	edge_t *crnt_edge;
	size_t max_depth, edge_depth;

	/* perform action on visited vertex and set visited true */
	action(vertex, crnt_depth);
	visited[vertex->index] = 1;

	max_depth = crnt_depth;
	crnt_edge = vertex->edges;
	while (crnt_edge != NULL)
	{
		if (!visited[crnt_edge->dest->index])
		{
			edge_depth = dfsrec(crnt_edge->dest,
								action,
								crnt_depth + 1,
								visited);
			if (edge_depth > max_depth)
				max_depth = edge_depth;
		}
		crnt_edge = crnt_edge->next;
	}
	return (max_depth);
}
