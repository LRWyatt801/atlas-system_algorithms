CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
MAIN_SRC := ./main_files/
QUEUES := -lqueues
GRAPHS := -lgraphs

backtracking_array: $(MAIN_SRC)0-main.c 0-backtracking_array.c
	$(CC) $(CFLAGS) -o $@ $^ $(QUEUES)
