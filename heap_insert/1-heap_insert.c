#include "binary_trees.h"

/**
 * swap_nodes - swap
 * @node: node
 * Return: void
 */
heap_t *swap_nodes(heap_t *node)
{
	heap_t *parent;
	int tmp;

	parent = node->parent;
	if (!parent)
		return (node);
	tmp = node->n;
	node->n = parent->n;
	parent->n = tmp;
	return (parent);
}
/**
 * get_heap_height - height
 * @root: root
 * Return: height
 */
int get_heap_height(heap_t *root)
{
	int l, r;

	if (!root)
		return (0);
	l = get_heap_height(root->left);
	r = get_heap_height(root->right);
	if (l > r)
		return (l + 1);
	return (r + 1);
}

/**
 * get_heap_count - height
 * @root: root
 * Return: height
 */
int get_heap_count(heap_t *root)
{
	int l, r;

	if (!root)
		return (0);
	l = get_heap_count(root->left);
	r = get_heap_count(root->right);
	return (l + r + 1);
}

/**
 * insert_tree - insert
 * @root: root
 * @value: value
 * Return: something
 */
heap_t *insert_tree(heap_t *root, int value)
{
	int c, h, i, j, n, k;

	if (!root->left)
	{
		root->left = binary_tree_node(root, value);
		return (root->left);
	}
	if (!root->right)
	{
		root->right = binary_tree_node(root, value);
		return (root->right);
	}
	c = get_heap_count(root);
	h = get_heap_height(root);
	n = c - 1;
	for (i = 1, n = c - 1; i <= (h - 2); i++, n -= k)
		for (j = 0, k = 1; j < i; j++)
			k *= 2;
	for (j = 0, k = 1; j < (h - 1); j++)
		k *= 2;
	if ((n < (k / 2)) || (n == k))
		return (insert_tree(root->left, value));
	return (insert_tree(root->right, value));
}

/**
 * heap_insert - create node
 * @root: root
 * @value: value
 * Return: new
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *h, *new;

	h = *root;
	if (!h)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new = insert_tree(*root, value);
	/*heapify(*root, new);*/
	while (new->parent)
	{
		if (new->parent->n > new->n)
			break;
		new = swap_nodes(new);
	}
	return (new);
}