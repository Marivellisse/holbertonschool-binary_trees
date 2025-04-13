#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the new root after rotation, or NULL on failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->right)
		return (NULL);

	pivot = tree->right;
	tree->right = pivot->left;

	if (pivot->left)
		pivot->left->parent = tree;

	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}

