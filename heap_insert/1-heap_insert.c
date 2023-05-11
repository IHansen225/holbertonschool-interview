# include <stdio.h>
# include <stdlib.h>
# include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = malloc(sizeof(heap_t));
    heap_t *current = *root;
    heap_t *parent = NULL;

    if (new_node == NULL) {
        return (NULL);
    }

    new_node->n = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
        return (new_node);
    }

    while (current != NULL) {
        parent = current;
        current = current->left;
    }

    if (parent->left == NULL) {
        parent->left = new_node;
        new_node->parent = parent;
    } else {
        parent->right = new_node;
        new_node->parent = parent;
    }

    return (new_node);
}