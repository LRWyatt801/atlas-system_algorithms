#include "graphs.h"

#include <stdlib.h>

/**
 * graph_delete - deletes a graph completely, vertices, edges, and graph
 * @graph: graph to be deleted
 *
 * Return: n/a
 */

void graph_delete(graph_t *graph)
{
	vertex_t *tmp_vertex, *crnt_vertex;
	edge_t *tmp_edge, *crnt_edge;

	if (!graph)
		return;

	crnt_vertex = graph->vertices;
	while (crnt_vertex != NULL)
	{
		if (crnt_vertex->nb_edges > 0)
		{
			crnt_edge = crnt_vertex->edges;
			while (crnt_edge != NULL)
			{
				tmp_edge = crnt_edge;
				crnt_edge = crnt_edge->next;
				free(tmp_edge);
			}
		}
		/* move crnt_vertex to next so tmp can be freed */
		tmp_vertex = crnt_vertex;
		crnt_vertex = crnt_vertex->next;
		free(tmp_vertex->content);
		free(tmp_vertex);
	}
	free(graph);
}
