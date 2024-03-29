#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    // Ensure stack is valid and contains at least two elements
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Swap the values of the top two elements
    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}