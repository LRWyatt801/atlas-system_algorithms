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

    graph_delete(graph);

    return (EXIT_SUCCESS);
}

/* OUTPUT

RUN WITH VALGRIND

==9712== Memcheck, a memory error detector
==9712== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==9712== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==9712== Command: ./3-graph_delete
==9712== 
Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0
==9712== 
==9712== HEAP SUMMARY:
==9712==     in use at exit: 0 bytes in 0 blocks
==9712==   total heap usage: X allocs, X frees, Y bytes allocated
==9712== 
==9712== All heap blocks were freed -- no leaks are possible
==9712== 
==9712== For counts of detected and suppressed errors, rerun with: -v
==9712== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/