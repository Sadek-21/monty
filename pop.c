#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 


/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    // Ensure stack is valid and not empty
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Store the top element temporarily
    stack_t *temp = *stack;

    // Move the stack pointer to the next element
    *stack = (*stack)->next;

    // Free the memory of the top element
    free(temp);
}
