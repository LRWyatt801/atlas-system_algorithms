#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex(node) to an existing graph
 * @graph: pointer to the graph to add the vertex to
 * @str: string to store in the new vertex
 *
 * Return: pointer to the created vertex, or NULL on failure
 */

vertex_t *graph_add_edge(graph_t *graph, const char *str)
{
	vertex_t *new_vertex;

	if (!graph || !str)
		return (NULL);

	/* TODO add code to add new vertex */

	return (new_vertex);
}