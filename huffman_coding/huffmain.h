#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>

/*****************************************************************************/
/****************************** PROVIDED STRUCT ******************************/

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

/************************ PROVIDED PROTOTYPES ********************************/

/*****************************************************************************/

#endif /* HUFFMAN_H */