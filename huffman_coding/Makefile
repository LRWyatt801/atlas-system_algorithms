CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
MAIN_SRC := ./main_files
PRINT_SRC := ./main_files/print #add print
HEAP_SRC := ./heap
HEAP_INC := -Iheap/ -I./

heap_create: $(HEAP_SRC)/0-heap_create.c $(MAIN_SRC)/0-main.c
	$(CC) $(CFLAGS) $^ -o $@