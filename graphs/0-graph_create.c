#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * graph_create - allocates memory to store a graph_t structure
 *
 * Return: pointer to allocated memory or NULL on failure
 */

graph_t *graph_create(void)
{
	graph_t *new_graph = malloc(sizeof(graph_t));

	if (!new_graph)
	{
		perror("graph_create: malloc");
		return (NULL);
	}
	return (new_graph);
}
