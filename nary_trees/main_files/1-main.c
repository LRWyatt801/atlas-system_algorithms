#include <stdlib.h>
#include <stdio.h>

#include "../nary_trees.h"

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

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}

/*****************************************************************************/
/***************************** OUTPUT *****************************************

RUN with valgrind

==26867== Memcheck, a memory error detector
==26867== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==26867== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==26867== Command: ./1-nary_tree_delete
==26867== 
==26867== 
==26867== HEAP SUMMARY:
==26867==     in use at exit: 0 bytes in 0 blocks
==26867==   total heap usage: X allocs, X frees, Y bytes allocated
==26867== 
==26867== All heap blocks were freed -- no leaks are possible
==26867== 
==26867== For counts of detected and suppressed errors, rerun with: -v
==26867== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

******************************************************************************/
