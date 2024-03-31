#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, or EXIT_FAILURE on failure
 */
bus_t bus;

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    /* Validate the number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty file */
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read lines from the file and execute Monty commands */
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        counter++;
        if (read_line > 0)
        {
            execute(content, &stack, counter, file);
        }
        free(content);
    }

    /* Free the stack and close the file */
    free_stack(stack);
    fclose(file);

    return (0);
}

