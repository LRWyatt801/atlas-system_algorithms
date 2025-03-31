CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
MAIN_SRC := ./main_files
PRINT_SRC := ./main_files/binary_tree_print.c
HEAP_SRC := ./heap
HEAP_INC := -Iheap/ -I./

heap_create: $(HEAP_SRC)/heap_create.c $(MAIN_SRC)/0-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $^ -o $@