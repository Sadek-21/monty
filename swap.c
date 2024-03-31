#include "monty.h"

/**
 * swap_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 * Return: No return value.
 */
void swap_elements(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, temp;

    /* Calculate the length of the stack*/
    current_node = *stack;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }

    /* Check if the stack has less than two elements*/
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Swap the top two elements of the stack*/
    current_node = *stack;
    temp = current_node->n;
    current_node->n = current_node->next->n;
    current_node->next->n = temp;
}

