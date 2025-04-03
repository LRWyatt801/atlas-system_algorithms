CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
MAIN_SRC := ./main_files
PRINT_SRC := ./main_files/binary_tree_print.c
HEAP_SRC := ./heap/*.c
HEAP_INC := -Iheap/ -I./

heap_create: $(HEAP_SRC)/heap_create.c $(MAIN_SRC)/0-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $^ -o $@

binary_tree_node: $(HEAP_SRC) $(MAIN_SRC)/1-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $^ -o $@

heap_insert: $(HEAP_SRC) $(MAIN_SRC)/2-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $(PRINT_SRC) $^ -o $@

heap_extract: $(HEAP_SRC) $(MAIN_SRC)/3-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $(PRINT_SRC) $^ -o $@

heap_delete: $(HEAP_SRC) $(MAIN_SRC)/4-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $(PRINT_SRC) $^ -o $@

symbol_create: $(HEAP_SRC) symbol.c $(MAIN_SRC)/5-main.c
	$(CC) $(CFLAGS) $(HEAP_INC) $(PRINT_SRC) $^ -o $@

clean:
	rm -f heap_create binary_tree_node heap_insert heap_extract heap_delete symbol_create
