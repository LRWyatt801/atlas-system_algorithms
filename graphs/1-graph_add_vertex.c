#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * graph_add_vertex - adds a vertex(node) to an existing graph
 * @graph: pointer to the graph to add the vertex to
 * @str: string to store in the new vertex
 *
 * Return: pointer to the created vertex, or NULL on failure
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *tmp;
	size_t i = 0;

	if (!str)
		return (NULL);
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
	{
		perror("graph_add_vertex: malloc error");
		return (NULL);
	}
	new_vertex->index = 0;
	new_vertex->content = strdup(str);
	if (!new_vertex->content)
	{
		free(new_vertex);
		perror("graph_add_vertex: strdup");
		return (NULL);
	}
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;
	if (!graph->vertices)
		graph->vertices = new_vertex;
	else
	{
		tmp = graph->vertices;
		while (tmp->next != NULL)
		{
			if (strcmp(tmp->content, str) == 0)
				return (NULL);
			tmp = tmp->next;
			i++;
		}
		new_vertex->index = i + 1;
		tmp->next = new_vertex;
	}
	graph->nb_vertices++;
	return (new_vertex);
}
