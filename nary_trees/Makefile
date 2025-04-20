CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
MAIN_SRC := ./main_files/

nary_tree_insert: $(MAIN_SRC)0-main.c 0-nary_tree_insert.c
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -rf nary_tree_insert
