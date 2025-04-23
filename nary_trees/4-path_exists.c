#include "nary_trees.h"
#include <string.h>

/**
 * path_exists - checks if a path exists in an N-ary tree
 * @root: pointer to root node
 * @path: NULL-terminated array of strings
 *
 * Return: 1 if path exists, 0 otherwise
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t i;
	nary_tree_t const *current, *child;

	if (!root || !path || !path[0])
		return (0);

	current = root;

	for (i = 0; path[i]; i++)
	{
		if (!current || !current->content || strcmp(current->content,
							    path[i]) != 0)
			return (0);

		/* If next path element exists, search children for it */
		if (path[i + 1])
		{
			child = current->children;
			current = NULL;
			while (child)
			{
				if (child->content && strcmp(child->content,
							     path[i + 1]) == 0)
				{
					current = child;
					break;
				}
				child = child->next;
			}
		}
	}

	return (1);
}

