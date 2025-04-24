#include "binary_trees.h"
#include "limits.h"

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Helper to check if tree is AVL
 * @tree: Pointer to the root node
 * Return: 1 if tree is AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (1);

	lh = height(tree->left);
	rh = height(tree->right);

	if (abs(lh - rh) > 1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);
	return (is_avl(tree));
}

