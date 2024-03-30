#include "monty.h"

/**
 * print_stack - Prints the elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being interpreted from the Monty file
 * Return: No return value
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;
    (void)line_number; // Unused parameter

    // Set current_node to the head of the stack
    current_node = *stack;

    // If stack is empty, return
    if (current_node == NULL)
        return;

    // Traverse the stack and print each element
    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

