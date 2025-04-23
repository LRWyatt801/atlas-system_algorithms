CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
MAIN_SRC := ./main_files/

0-nary_tree_insert: $(MAIN_SRC)0-main.c 0-nary_tree_insert.c
	$(CC) $(CFLAGS) -o $@ $^

1-nary_tree_delete: $(MAIN_SRC)1-main.c 0-nary_tree_insert.c 1-nary_tree_delete.c
	$(CC) $(CFLAGS) -o $@ $^

2-nary_tree_traverse: $(MAIN_SRC)2-main.c 0-nary_tree_insert.c 1-nary_tree_delete.c 2-nary_tree_traverse.c
	$(CC) $(CFLAGS) -o $@ $^

3-nary_tree_diameter: $(MAIN_SRC)3-main.c 0-nary_tree_insert.c 1-nary_tree_delete.c 3-nary_tree_diameter.c
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -rf 0-nary_tree_insert 1-nary_tree_delete 2-nary_tree_traverse 3-nary_tree_diameter
