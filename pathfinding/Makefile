CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
MAIN_SRC := ./main_files/
INCL := -L./main_files/path_libraries/
QUEUES := -lqueues
GRAPHS := -lgraphs

backtracking_array: $(MAIN_SRC)0-main.c 0-backtracking_array.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(QUEUES)

backtracking_graph: $(MAIN_SRC)1-main.c 1-backtracking_graph.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(QUEUES) $(GRAPHS)

dijkstra_graph: $(MAIN_SRC)2-main.c 2-dijkstra_graph.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(QUEUES) $(GRAPHS)

dijkstra_graph_1: $(MAIN_SRC)2-main_1.c 2-dijkstra_graph.c
	$(CC) $(CFLAGS) -o $@ $^ $(INCL) $(QUEUES) $(GRAPHS)


