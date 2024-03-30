#include "monty.h"

/**
 * perform_addition - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 * Return: No return value.
 */
void perform_addition(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, sum;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *stack = current->next;
    free(current);
}
