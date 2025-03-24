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

    if (!graph_add_vertex(graph, "San Francisco") ||
        !graph_add_vertex(graph, "Seattle") ||
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

    if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
    {
        fprintf(stderr, "Failed to add edge\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    return (EXIT_SUCCESS);
}

/* OUTPUT

Currently output does not match.  There is an error in main.
2-graph_add_edge.c passed all checks except one

Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0

*/