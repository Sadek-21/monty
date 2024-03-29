#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack; // Unused parameter
    (void)line_number; // Unused parameter
    // Does nothing
}
