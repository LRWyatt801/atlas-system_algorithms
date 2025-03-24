#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int unidirectional_edge(vertex_t *, vertex_t*);
int bidirectional_edge(vertex_t *, vertex_t*);

/**
 * graph_add_edge - adds an edge between two vertices(nodes)
 *					of an existing graph
 * @graph: pointer to the graph to add the edge to
 * @str: string identifying the vertex to make the connection from
 * @dest: srting identifying the vertex to connect to
 * @type: is the type of edge
 *	UNIDIRECTIONAL - only one edge is created connecting src to dest
 *	BIDIRECTIONAL - two edges are created, connecting src to dest
 *					AND dest to src
 *
 * Return: 1 on success, or 0 on failure
 */

int graph_add_edge(graph_t *graph,
				   const char *str,
				   const char *dest,
				   edge_type_t type)
{
	vertex_t *tmp_src = NULL, *tmp_dest = NULL, *tmp_vertex = NULL;

	/* check for NULL inputs */
	if (!graph || !graph->vertices || !str || !dest)
		return (0);

	/* get vertex pointers */
	tmp_vertex = graph->vertices;
	while (tmp_vertex != NULL)
	{
		if (strcmp(tmp_vertex->content, str) == 0)
			tmp_src = tmp_vertex;
		if (strcmp(tmp_vertex->content, dest) == 0)
			tmp_dest = tmp_vertex;
		tmp_vertex = tmp_vertex->next;
	}
	if (!tmp_src || !tmp_dest)
		return (0);

	/* set edge */
	if (unidirectional_edge(tmp_src, tmp_dest) == 0)
		return (0);
	if (type == BIDIRECTIONAL)
	{
		if (unidirectional_edge(tmp_dest, tmp_src) == 0)
			return (0);
	}
	return (1);
}

/**
 * unidirectional_edge - creates an edge from src to dest
 * @src: pointer to src vertex
 * @dest: pointer to dest vertex
 *
 * Return: 1 on success, 0 on failure
 */

int unidirectional_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *new_edge, *tmp_edge;

	if (!src || !dest)
		return (0);

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);
	new_edge->dest = dest;
	new_edge->next = NULL;
	if (src->edges == NULL)
		src->edges = new_edge;
	else
	{
		tmp_edge = src->edges;
		while (tmp_edge->next != NULL)
		{
			if (tmp_edge->dest == dest)
			{
				free(new_edge);
				return (0);
			}
			tmp_edge = tmp_edge->next;
		}
		tmp_edge->next = new_edge;
	}
	src->nb_edges++;
	return (1);
}
