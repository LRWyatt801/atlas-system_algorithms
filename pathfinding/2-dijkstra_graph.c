#include "main_files/path_libraries/graphs.h"
#include "main_files/path_libraries/queues.h"
#include "pathfinding.h"

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TMPINDEX tmp_node->index
#define CRNTINDEX crnt_node->index

static queue_t *build_queue(vertex_t const *start, vertex_t const *target,
		   vertex_t *prev_node[]);
static void find_distance(graph_t *graph, vertex_t const *start,
			  vertex_t const *target, int visited[],
			  int distance[], vertex_t *prev_node[]);


/**
* dijkstra_graph - searchs a graph to find the shortest path
*		   from start to target
* @graph: graph to search
* @start: starting point to search from
* @target: target to search for
*
* Return: queue containing shortest path, or NULL on failure
*/

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
			vertex_t const *target)
{
	if (!graph || !start || !target)
		return (NULL);

	int visited[graph->nb_vertices], distance[graph->nb_vertices];
	vertex_t *prev_node[graph->nb_vertices];
	size_t i;

	/* initialize arrays */
	for (i = 0; i < graph->nb_vertices; i++)
	{
		visited[i] = 0;
		distance[i] = INT_MAX;
		prev_node[i] = NULL;
	}
	distance[start->index] = 0;

	find_distance(graph, start, target, visited, distance, prev_node);
	if (prev_node[target->index] == NULL)
		return (NULL);

	return (build_queue(start, target, prev_node));
}

/**
* build_queue - builds a path in a queue using an dijkstra array
* @start: start of path
* @target: target node to search for
* @prev_node: an array containing the shortes previous node
*
* Return: a queue containing a path from start to target
*/

static queue_t *build_queue(vertex_t const *start, vertex_t const *target,
		   vertex_t *prev_node[])
{
	if (!start || !target || !prev_node)
		return (NULL);

	vertex_t *crnt_node;
	queue_t *queue = queue_create();

	if (!queue)
		return (NULL);

	for (crnt_node = (vertex_t *)target; crnt_node != NULL;
	     crnt_node = prev_node[crnt_node->index])
		queue_push_front(queue, strdup(crnt_node->content));

	return (queue);
}

/**
* find_distance - finds the shortest distance between nodes
* @graph: a graph data structure to search through
* @start: start point to search from
* @target: target point to search from
* @visited: an array containing a true/false if node is visited
* @distance: an array containing the distance from node
* @prev_node: an array containing the prev closest node
*
* Return: n/a
*/

static void find_distance(graph_t *graph, vertex_t const *start,
			  vertex_t const *target, int visited[],
			  int distance[], vertex_t *prev_node[])
{
	int min_distance, tmp_distance;
	vertex_t *crnt_node = NULL, *tmp_node = NULL;
	edge_t *edge_ptr = NULL;

	while (crnt_node != target)
	{
		min_distance = INT_MAX, tmp_distance = 0;
		crnt_node = NULL, tmp_node = NULL, edge_ptr = NULL;

		for (tmp_node = graph->vertices; tmp_node != NULL;
		     tmp_node = tmp_node->next)
		{
			if (!visited[TMPINDEX] &&
			    distance[TMPINDEX] < min_distance)
			{
				min_distance = distance[TMPINDEX];
				crnt_node = tmp_node;
			}
		}

		if (!crnt_node)
			break;
		printf("Checking %s, distance from %s is %d\n",
		       crnt_node->content, start->content, min_distance);

		visited[CRNTINDEX] = 1;
		for (edge_ptr = crnt_node->edges; edge_ptr;
		     edge_ptr = edge_ptr->next)
		{
			tmp_node = edge_ptr->dest;
			tmp_distance = distance[CRNTINDEX] + edge_ptr->weight;
			if (tmp_distance < distance[TMPINDEX])
			{
				distance[TMPINDEX] = tmp_distance;
				prev_node[TMPINDEX] = crnt_node;
			}
		}
	}
}

