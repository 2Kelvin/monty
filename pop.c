#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * pop - delete the stack's top node
  * @stack: myStack
  * @line_number: lineNo
  * Return: void
  */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->prev == NULL)
		(*stack)->next = NULL;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
}
