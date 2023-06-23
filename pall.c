#include "monty.h"
#include <stdio.h>

/**
  * pall - print stack elements' data
  * @stack: myStack
  * @line_number: lineNo
  * Return: void
  */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	while (*stack != NULL && line_number != 0)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
}
