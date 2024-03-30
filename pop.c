#include "monty.h"

/**
 * perform_pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 * Return: No return value.
 */
void perform_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    *stack = current->next;
    free(current);
}
