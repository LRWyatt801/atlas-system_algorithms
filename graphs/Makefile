CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
MAINS := ./main_files
PRINT := ./main_files/graph_display.c

graph_create: 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/0-main.c

graph_add_vertex: 1-graph_add_vertex.c 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/1-main.c

graph_add_edge: 2-graph_add_edge.c 1-graph_add_vertex.c 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/2-main.c

graph_delete: 3-graph_delete.c 2-graph_add_edge.c 1-graph_add_vertex.c 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/3-main.c

depth_first_traverse: 4-depth_first_traverse.c 3-graph_delete.c 2-graph_add_edge.c 1-graph_add_vertex.c 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/4-main.c

breadth_first_traverse: 5-breadth_first_traverse.c 4-depth_first_traverse.c 3-graph_delete.c 2-graph_add_edge.c 1-graph_add_vertex.c 0-graph_create.c
	$(CC) $(CFLAGS) -o $@ $^ $(PRINT) $(MAINS)/5-main.c

clean:
	rm -f graph_create graph_add_vertex graph_add_edge graph_delete depth_first_traverse breadth_first_traverse
