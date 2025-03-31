#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
        binary_tree_print(heap->root, print_int);
        printf("\n");
    }
    printf("Heap size: %lu\n", heap->size);
    heap_delete(heap, NULL);
    return (EXIT_SUCCESS);
}

/*****************************************************************************/
/****************************** OUTPUT ***************************************/

/*

RUN WITH VALGRIND

==102349== Memcheck, a memory error detector
==102349== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102349== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102349== Command: ./heap_delete
==102349== 
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
==102349== 
==102349== HEAP SUMMARY:
==102349==     in use at exit: 0 bytes in 0 blocks
==102349==   total heap usage: 36 allocs, 36 frees, 3,373 bytes allocated
==102349== 
==102349== All heap blocks were freed -- no leaks are possible
==102349== 
==102349== For counts of detected and suppressed errors, rerun with: -v
==102349== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/