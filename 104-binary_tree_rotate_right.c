#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the new root after rotation, or NULL if not possible
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->left)
		return (NULL);

	pivot = tree->left;
	tree->left = pivot->right;

	if (pivot->right)
		pivot->right->parent = tree;

	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}

