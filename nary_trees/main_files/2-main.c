#include <stdlib.h>
#include <stdio.h>

#include "../nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_traverse(root, &print_node);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}

/*****************************************************************************/
/****************************** OUTPUT ****************************************

/
  home
    alex
      Applications
      Documents
      Movies
      Pictures
      Downloads
      Desktop
  opt
    Betty
      betty-doc.pl
      betty-style.pl
  var
    www
  tmp
    tmp_file

******************************************************************************/
