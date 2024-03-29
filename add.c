#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    // Ensure stack is valid and contains at least two elements
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Add the top two elements and store the result in the second element
    (*stack)->next->n += (*stack)->n;

    // Pop the top element
    pop(stack, line_number);
}
