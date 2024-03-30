#include "monty.h"

/**
 * perform_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 * Return: No return value.
 */
void perform_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
