#include "huffman.h"

#include <stdlib.h>

/**
* symbol_create - creates a symbol_t structure
* @data: data to be store in structure
* @freq: frequency of associated data
*
* Return: pointer to the created structure, on failure NULL
*/

symbol_t *symbol_create(char data, size_t freq)
{
	if (!data || !freq)
		return (NULL);

	symbol_t *new_sym = NULL;

	new_sym = malloc(sizeof(symbol_t));
	if (!new_sym)
		return (NULL);

	new_sym->data = data;
	new_sym->freq = freq;
	return (new_sym);
}
