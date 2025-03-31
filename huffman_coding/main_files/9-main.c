#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    if (!huffman_codes(data, freq, size))
    {
        fprintf(stderr, "Failed to get Huffman codes\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/*****************************************************************************/
/************************************* OUTPUT ********************************/

/*

RUN WITH VALGRIND

==102860== Memcheck, a memory error detector
==102860== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102860== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102860== Command: ./huffman_codes
==102860== 
f: 0
c: 100
d: 101
e: 110
a: 1110
b: 1111
==102860== 
==102860== HEAP SUMMARY:
==102860==     in use at exit: 0 bytes in 0 blocks
==102860==   total heap usage: 111 allocs, 111 frees, 2,592 bytes allocated
==102860== 
==102860== All heap blocks were freed -- no leaks are possible
==102860== 
==102860== For counts of detected and suppressed errors, rerun with: -v
==102860== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/