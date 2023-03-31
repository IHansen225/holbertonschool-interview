#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number) {

    listint_t *new_node, *prev_node, *current_node;

    if (!head) {
        return NULL;
    }
    prev_node = NULL;
    current_node = *head;
    while (current_node && current_node->n < number) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    new_node = malloc(sizeof(listint_t));
    if (!new_node) {
        return NULL;
    }
    new_node->n = number;
    new_node->next = current_node;
    if (!prev_node) {
        *head = new_node;
    } else {
        prev_node->next = new_node;
    }

    return new_node;
}
