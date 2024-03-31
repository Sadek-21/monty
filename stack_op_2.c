#include "monty.h"

/**
 * add_node_to_queue - Adds a new node at the end of a doubly linked list
 * @stack: Pointer to the head of the doubly linked list
 * @value: Value to be stored in the new node
 * Return: Pointer to the newly created node, or NULL on failure
 */

void add_node_to_stack(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}


stack_t *add_node_to_queue(stack_t **stack, int value)
{
    stack_t *new_node, *temp;

    if (!stack)
        return (NULL);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (!*stack)
    {
        *stack = new_node;
        return (new_node);
    }

    temp = *stack;
    while (temp->next)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    return (new_node);
}

