# Huffman Coding

Huffman coding is an algorithm used in loseless compression.  It consists of finding the frequency of characters in a file, building a binary heap, and finally building a huffman tree.  Which is then used to asign characters a smaller bit combination based on position in the huffman tree.

The tasks I was required to do were:
- ```heap_create``` - creates a Min Binary Heap data structure in memory
- ```binary_tree_node``` - creates Node in memory for a Min Binary Heap
- ```heap_insert``` - inserts a Node in Min Binary Heap
- ```heap_extract``` - extracts a Node from Min Binary Heap
- ```heap_delete``` - deallocates a Min Binary Heap from memory
- ```symbol_create``` - creates a Symbol data structure in memory - stuct to hold frequency and character
- ```priority_heap``` - builds a Priority Queue
- ```extract``` - extracts from Priority Queue
- ```huffman_tree``` - builds a Huffman Tree
- ```huffman_codes``` - assigns the Huffman Codes

## Learning Objectives

- What is a binary heap (min and max)
- What is a priority queue
- What is Huffman Code

### Provided code and Headers

Within ```huffman.h``` and ```heap/heap.h``` will be provided structs.  I will also be adding any prototypes and any other data types I need.

### Example Main Functions

In the folder ```main_files``` will be the provided main files to test each given task.  Each main file will include the ```main()``` and the expected output.
