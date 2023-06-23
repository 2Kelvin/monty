#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * push - add new node in stack
  * @stack: myStack
  * @line_number: lineNo
  * Return: void
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newTopNode;

	newTopNode = malloc(sizeof(stack_t));
	if (newTopNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!line_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n" line_number);
		exit(EXIT_FAILURE);
	}

	newTopNode->n = line_number;
	if (*stack == NULL)
	{
		newTopNode->prev = NULL;
		newTopNode->next = NULL;
		*stack = newTopNode;
	}
	else
	{
		newTopNode->prev = *stack;
		(*stack)->next = newTopNode;
		*stack = newTopNode;
	}
}
