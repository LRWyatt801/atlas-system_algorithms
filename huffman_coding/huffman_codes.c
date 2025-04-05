#include "heap/heap.h"
#include "huffman.h"

#include <stdlib.h>

void rec_print_huff(binary_tree_node_t *, size_t);
void print_binary(size_t);
void free_huff(binary_tree_node_t *);

/**
* huffman_codes - prints the resulting huffman codes for each symbol
* @data: an array containing characters
* @freq: an array of corresponding frequencies
* @size: size of arrays
*
* Return: 1 on success, 0 on failure
*/

int huffman_codes(char *data, size_t *freq, size_t size)
{
	size_t huff_code = 0;
	binary_tree_node_t *root;

	root = huffman_tree(data, freq, size);

	rec_print_huff(root, huff_code);
	free_huff(root);
	return (1);
}

/**
* rec_print_huff - recursivly print the huffman codes
* @node: node to print
* @code: current code
*
* Return: n/a
*/

void rec_print_huff(binary_tree_node_t *node, size_t code)
{
	symbol_t *sym = NULL;

	if (!node)
		return;

	sym = (symbol_t *)node->data;

	if (sym && sym->data != -1)
	{
		printf("%c: ", sym->data);
		print_binary(code);
		printf("\n");
	}
	else
	{
		rec_print_huff(node->left, code << 1);
		rec_print_huff(node->right, (code << 1) | 1);
	}
}

/**
* print_binary - prints a size_t in binary
* @code: code to print
*
* Return: n/a
*/

void print_binary(size_t code)
{
	int i = 0;
	int ones = 0;
	unsigned long int shift;

	for (i = 63; i >= 0; i--)
	{
		shift = code >> i;

		if (shift & 1)
		{
			putchar('1');
			ones++;
		}
		else if (ones)
			putchar ('0');
	}
	if (ones == 0)
		putchar ('0');
}

/**
* free_huff - frees the nodes of a huffman tree
* @node: pointer to a node of the huffman tree
*
* Return: n/a
*/

void free_huff(binary_tree_node_t *node)
{
	if (!node)
		return;

	free_huff(node->left);
	free_huff(node->right);
	free(node->data);
	free(node);
}
