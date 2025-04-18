#include "main_files/path_libraries/graphs.h"
#include "main_files/path_libraries/queues.h"
#include "pathfinding.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INDEX(node) (node->index)

int dfs_btg(queue_t *queue, int visited[], graph_t *graph,
	    vertex_t *start, vertex_t const *target);

/**
* backtracking_graph - searches for the first path from the starting point to
*		       target
* @graph: graph to search
* @start: start of search
* @target: target to search for
*
* Return: pointer to the queued search path, or NULL on failure
*/

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
			    vertex_t const *target)
{
	if (!graph || !start || !target)
		return (NULL);

	queue_t *queue = queue_create();
	int visited[graph->nb_vertices];
	size_t i;

	if (!queue)
		return (NULL);
	/* setup visited array all visited = false */
	for (i = 0; i < graph->nb_vertices; i++)
		visited[i] = 0;

	if (!dfs_btg(queue, visited, graph, (vertex_t *)start, target))
	{
		free(queue);
		return (NULL);
	}
	return (queue);
}

/**
* dfs_btg - traverse a graph using depth first search
*	    for a path from start to target
* @queue: queue containing the current path
* @visited: array containing true/false for if node is visited
* @graph: graph to search through
* @start: node to search from
* @target: target node searching for
*
* Return: 1 on success, 0 on failure
*/

int dfs_btg(queue_t *queue, int visited[], graph_t *graph,
	    vertex_t *start, vertex_t const *target)
{
	if (!queue || !visited || !graph || !start || !target)
		return (0);

	edge_t *crnt_edge = NULL;

	visited[INDEX(start)] = 1;
	printf("Checking %s\n", start->content);
	if (start->content == target->content)
		return (1);
	crnt_edge = start->edges;
	while (crnt_edge != NULL)
	{
		if (!visited[INDEX(crnt_edge->dest)])
			if (dfs_btg(queue, visited, graph,
			crnt_edge->dest, target))
			{
				queue_push_front(queue, strdup(start->content));
				return (1);
			}
		crnt_edge = crnt_edge->next;
	}
	return (0);
}
