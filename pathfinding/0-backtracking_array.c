#include "main_files/path_libraries/queues.h"
#include "pathfinding.h"

#include <stdlib.h>
#include <stdio.h>

#define RIGHT(x) (x + 1)
#define BOTTOM(y) (y + 1)
#define LEFT(x) (x - 1)
#define TOP(y) (x - 1)

static int backtracking_rec(queue_t *queue, int **visited, char **map,
			    int rows, int cols, int x, int y,
			    point_t const *target);

/**
 * backtracking_array - searches for the first path from a starting point to a
 *		       target point within a two-dimensional array
 * @map: pointer to a read only 2d array
 * @rows: number of rows
 * @cols: number of columns
 * @start: coordinates of starting point
 * @target: coordinates of target point
 *
 * Return: a queue in which each node is point in the path from start to target
 */

queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target)
{
	if (!map || rows <= 0 || cols <= 0 || !start || !target)
		return (NULL);

	queue_t *queue = queue_create();
	int **visited = malloc(rows * sizeof(int *));
	int i;

	/* set all visited nodes to 0 */
	for (i = 0; i < rows; i++)
		visited[i] = calloc(cols, sizeof(int));

	/* Recursively navigate map */
	if (!backtracking_rec(queue, visited, map, rows, cols, start->x,
			      start->y, target))
	{
		for (i = 0; i < rows; i++)
			free(visited[i]);
		free(visited);
		free(queue);
		return (NULL);
	}

	return (queue);
}

/**
* backtracking_rec - recursively finds the first path to target
* @queue: a queue to store the path
* @visited: signifies if a node has been visited or not
* @map: pointer to a read only 2d array
* @rows: number of rows
* @cols: number of columns
* @start: coordinates of starting point
* @target: coordinates of target point
*
* Return: 1 if valid node, otherwise 0
*/

static int backtracking_rec(queue_t *queue, int **visited, char **map,
			    int rows, int cols, int x, int y,
			    point_t const *target)
{
	if (x < 0 || x >= cols ||
	    y < 0 || y >= rows ||
	    map[y][x] == '1' || visited[y][x])
		return (0);
	visited[y][x] = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == target->x && y == target->y) ||
	    backtracking_rec(queue, visited, map, rows, cols, RIGHT(x), y, target) ||
	    backtracking_rec(queue, visited, map, rows, cols, x, BOTTOM(y), target) ||
	    backtracking_rec(queue, visited, map, rows, cols, LEFT(x), y, target) ||
	    backtracking_rec(queue, visited, map, rows, cols, x, TOP(y), target))
	{
		point_t *crnt = malloc(sizeof(point_t));

		crnt->x = x;
		crnt->y = y;

		queue_push_front(queue, crnt);
		return (1);
	}
	else
		return (0);
}

