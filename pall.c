#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    // Ensure stack is valid
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: Error: stack not initialized\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Traverse the stack and print its contents
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
