#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
        return (*root = new_node);

    parent = find_parent(*root);
    new_node->parent = parent;

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify(new_node);

    return (new_node);
}

/**
 * find_parent - Finds the parent node of the last inserted node
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
    if (!root->left || !root->right)
        return (root);

    if (binary_tree_size(root->left) <= binary_tree_size(root->right))
        return (find_parent(root->left));
    else
        return (find_parent(root->right));
}

/**
 * heapify - Maintains the Max Heap property of the Heap
 * @node: Pointer to the newly inserted node
 */
void heapify(heap_t *node)
{
    heap_t *parent;
    int tmp;

    if (!node || !node->parent)
        return;

    parent = node->parent;
    if (node->n > parent->n)
    {
        tmp = node->n;
        node->n = parent->n;
        parent->n = tmp;

        heapify(parent);
    }
}

/**
 * binary_tree_size - Measures the size of a Binary Tree
 * @tree: Pointer to the root node of the Tree
 *
 * Return: Size of the Tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}