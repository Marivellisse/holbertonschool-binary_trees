#include "binary_trees.h"

/**
 * height - Measures height of a binary tree
 * @tree: Pointer to the node
 * Return: Height or 0
 */
size_t height(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree)
		return (0);
	l = height(tree->left);
	r = height(tree->right);
	return ((l > r ? l : r) + 1);
}

/**
 * level - Applies func to nodes at a given level
 * @tree: Pointer to the node
 * @lvl: Current level
 * @func: Function to call
 */
void level(const binary_tree_t *tree, size_t lvl, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (lvl == 1)
		func(tree->n);
	else
	{
		level(tree->left, lvl - 1, func);
		level(tree->right, lvl - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses binary tree using level-order
 * @tree: Pointer to root
 * @func: Function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;

	h = height(tree);
	for (i = 1; i <= h; i++)
		level(tree, i, func);
}

