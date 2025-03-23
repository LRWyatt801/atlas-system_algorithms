#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_vertex(vertex_t **, const char *);

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

	if (init_vertex(&new_vertex, str) == -1)
		return (NULL);

	if (!graph->vertices)
		graph->vertices = new_vertex;
	else
	{
		tmp = graph->vertices;
		while (tmp->next != NULL)
		{
			if (strcmp(tmp->content, str) == 0)
				goto cleanup;
			tmp = tmp->next;
			i++;
		}
		if (strcmp(tmp->content, str) == 0)
			goto cleanup;
		new_vertex->index = i + 1;
		tmp->next = new_vertex;
	}
	graph->nb_vertices++;
	return (new_vertex);

cleanup:
	free(new_vertex->content);
	free(new_vertex);
	return (NULL);
}

/**
 * init_vertex - inits a vertex with given values
 * @vertex: vertex to init
 * @str: string to init content with
 *
 * Return: 0 on success, otherwise -1
 */

int init_vertex(vertex_t **vertex, const char *str)
{
	(*vertex)->index = 0;
	(*vertex)->content = strdup(str);
	if (!(*vertex)->content)
	{
		free(vertex);
		perror("init_vertex: strdup");
		return (-1);
	}
	(*vertex)->nb_edges = 0;
	(*vertex)->edges = NULL;
	(*vertex)->next = NULL;
	return (0);
}
