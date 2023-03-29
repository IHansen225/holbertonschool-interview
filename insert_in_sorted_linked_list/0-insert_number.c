#include <lists.h>

listint_t *insert_node(listint_t **head, int number) {
    
    listint_t *nelem, *next, *prev = NULL;

    if (!head) 
        return NULL;
    next = *head;
    while (next && next->n < number) {
        next = next->next;
    };
    if (!next) 
        return NULL;
    nelem = malloc(sizeof(listint_t)); 
    if (!nelem)
        return NULL;
    nelem->n = number;
    nelem->next = next->next;
    next->next = nelem;

    return (nelem);
};