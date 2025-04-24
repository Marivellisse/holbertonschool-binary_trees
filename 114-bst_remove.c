#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the minimum value in a subtree
 * @node: Pointer to the root node of the subtree
 * Return: Pointer to the node with the minimum value
 */
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;
	return (current);
}

/**
 * bst_remove - Removes a node with a specific value from a BST
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 * Return: Pointer to the new root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node found */
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->left)
		{
			temp = root->right;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		/* Two children: get in-order successor (smallest in right subtree) */
		temp = min_value_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

