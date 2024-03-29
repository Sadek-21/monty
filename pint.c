#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    // Ensure stack is valid and not empty
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Print the value at the top of the stack
    printf("%d\n", (*stack)->n);
}
