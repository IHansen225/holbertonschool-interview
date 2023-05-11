#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - restores the Max Heap ordering property of a binary tree
 * @node: pointer to the node to be heapified
 * Return: void
 */
void heapify(heap_t *node)
{
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
		max = node->left;

	if (node->right != NULL && node->right->n > max->n)
		max = node->right;

	if (max != node)
	{
		int temp = node->n;
		node->n = max->n;
		max->n = temp;
		heapify(max);
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = malloc(sizeof(heap_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	heap_t *current = *root;
	while (current->left != NULL)
		current = current->left;

	if (current->parent->right == NULL)
		current = current->parent;
	else
	{
		current = *root;
		while (current->right != NULL)
			current = current->right;
	}

	if (current->left == NULL)
	{
		current->left = new_node;
		new_node->parent = current;
	}
	else
	{
		current->right = new_node;
		new_node->parent = current;
	}

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		int temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}
