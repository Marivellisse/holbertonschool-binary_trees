#include "binary_trees.h"
#include <stdlib.h>

/**
 * queue_push - Pushes a node into the queue
 * @queue: Pointer to the queue
 * @rear: Pointer to the rear index
 * @node: Node to enqueue
 */
void queue_push(binary_tree_t **queue, int *rear, binary_tree_t *node)
{
	queue[(*rear)++] = node;
}

/**
 * queue_pop - Pops a node from the queue
 * @queue: Pointer to the queue
 * @front: Pointer to the front index
 *
 * Return: The popped node
 */
binary_tree_t *queue_pop(binary_tree_t **queue, int *front)
{
	return (queue[(*front)++]);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *node, **queue;
	int front = 0, rear = 0, found_null = 0;
	size_t size = 1024;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (0);

	queue_push(queue, &rear, (binary_tree_t *)tree);

	while (front < rear)
	{
		node = queue_pop(queue, &front);

		if (!node)
		{
			found_null = 1;
		}
		else
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue_push(queue, &rear, node->left);
			queue_push(queue, &rear, node->right);
		}
	}

	free(queue);
	return (1);
}

