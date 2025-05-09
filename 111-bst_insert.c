#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	while (current)
	{
		if (value < current->n)
		{
			if (!current->left)
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (!current->right)
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
		else
			return (NULL); /* No duplicados */
	}

	return (NULL);
}

