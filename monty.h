#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Define the stack structure */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Define the instruction structure */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void perform_pint(stack_t **stack, unsigned int line_number);
void perform_pop(stack_t **stack, unsigned int line_number);
void perform_addition(stack_t **stack, unsigned int line_number);
void perform_no_operation(stack_t **stack, unsigned int line_number);
void swap_elements(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void push_node(stack_t **stack, unsigned int line_number);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *stack);
extern bus_t bus;
#endif /* MONTY_H */

