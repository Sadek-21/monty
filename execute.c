#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", perform_push}, {"pall", print_stack}, {"pint", perform_pint},
        {"pop", perform_pop},
        {"swap", swap_elements},
        {"add", perform_addition},
        {"nop", perform_no_operation},
        // Add more opcodes here as needed
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *op;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return;

    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(stack, counter);
            return;
        }
        i++;
    }

    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}
