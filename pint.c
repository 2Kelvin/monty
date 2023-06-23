#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * pall - print the stack's top node's data
  * @stack: myStack
  * @line_number: lineNo
  * Return: void
  */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
