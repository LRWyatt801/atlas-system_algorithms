#include <stdlib.h>
#include <stdio.h>

#include "../graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }
	printf("graph created\n");

    if (!graph_add_vertex(graph, "San Francisco"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    };

    graph_display(graph);

    if (!graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    if (!graph_add_vertex(graph, "San Francisco"))
        fprintf(stderr, "Failed to add \"San Francisco\"\n");

    return (EXIT_SUCCESS);
}

/* OUTPUT 

Number of vertices: 1
[0] San Francisco
Number of vertices: 8
[0] San Francisco
[1] Seattle
[2] New York
[3] Miami
[4] Chicago
[5] Houston
[6] Las Vegas
[7] Boston
Failed to add "San Francisco"

*/