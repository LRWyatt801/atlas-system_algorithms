CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
MAINS := ./main_files/

rb_tree_node: $(MAINS)0-main.c 0-rb_tree_node.c $(MAINS)rb_tree_print.c
	$(CC) $(CFLAGS) -o $@ $^

rb_tree_valid: $(MAINS)1-main.c 1-rb_tree_is_valid.c 0-rb_tree_node.c  $(MAINS)rb_tree_print.c
	$(CC) $(CFLAGS) -o $@ $^

rb_tree_insert: $(MAINS)2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c $(MAINS)rb_tree_print.c
	$(CC) $(CFLAGS) -o $@ $^

rb_tree_insert_noW: $(MAINS)2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c $(MAINS)rb_tree_print.c
	$(CC) -o $@ $^

clean:
	rm -rf rb_tree_node rb_tree_valid rb_tree_insert rb_tree_insert_noW
