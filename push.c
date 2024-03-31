#include "monty.h"

/**
 * push_node - Adds a new node to the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number being interpreted from the Monty file
 * Return: No return value
 */
void push_node(stack_t **stack, unsigned int line_number)
{
    int value, index = 0, invalid_flag = 0;

    /* Check if the argument exists*/
    if (interpreter.argument)
    {
        /* Check if the argument is negative*/
        if (interpreter.argument[0] == '-')
            index++;

        /* Loop through the argument to check for non-digit characters*/
        for (; interpreter.argument[index] != '\0'; index++)
        {
            if (interpreter.argument[index] > '9' || interpreter.argument[index] < '0')
                invalid_flag = 1;
        }

        /* If non-digit characters found, print error message and exit*/
        if (invalid_flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(interpreter.file);
            free(interpreter.content);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* If no argument provided, print error message and exit*/
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(interpreter.file);
        free(interpreter.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer*/
    value = atoi(interpreter.argument);

    /* Add the value to the stack based on the stack type*/
    if (interpreter.lifo == 0)
        add_node_to_stack(stack, value);
    else
        add_node_to_queue(stack, value);
}

