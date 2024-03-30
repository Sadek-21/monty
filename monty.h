#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Struct for Monty interpreter */
typedef struct monty_interpreter {
    char *argument;
    int lifo;
    FILE *file;
    char *content;
} monty_interpreter_t;

/* Struct for stack nodes */
typedef struct stack_node {
    int n;
    struct stack_node *next;
} stack_t;

/* Function prototypes */
void perform_pint(stack_t **stack, unsigned int line_number);
void perform_pop(stack_t **stack, unsigned int line_number);
void perform_addition(stack_t **stack, unsigned int line_number);
void perform_no_operation(stack_t **stack, unsigned int line_number);
void swap_elements(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void push_node(stack_t **stack, unsigned int line_number);

/* Function to free the stack */
void free_stack(stack_t *stack);

#endif /* MONTY_H */

