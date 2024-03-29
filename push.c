#include <stdio.h>
#include <stdlib.h>
#include "monty.h" 
/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being interpreted from the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    // Ensure stack and line_number are valid
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: Error: stack not initialized\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Create a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Check if integer argument is provided
    if (global_argument == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }

    // Convert the argument to an integer
    new_node->n = atoi(global_argument);
    if (new_node->n == 0 && *global_argument != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }

    // Update links of the new node
    new_node->prev = NULL;
    new_node->next = *stack;

    // Update previous head's prev pointer if stack is not empty
    if (*stack != NULL)
        (*stack)->prev = new_node;

    // Update stack to point to the new node
    *stack = new_node;
}
