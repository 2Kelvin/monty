#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
  * main - monty bytecode intepreter
  * @argc: arg count
  * @argv: args
  * Return: 0 for success
  */

int main(int argc, char *argv[])
{
	FILE *byteFile;
	stack_t *myStack;
	unsigned int lineNo = 1;
	char byteLine[260];
	instruction_t arrInstructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	byteFile = fopen(argv[1], "r");
	if (byteFile == NULL)
	{
		fprintf(stderr, "Error. Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(byteLine, sizeof(byteLine), byteFile))
	{
		if ((strstr(byteLine, arrInstructions[0].opcode)) != NULL)
			arrInstructions[0].f(&myStack, lineNo);
		else if ((strstr(byteLine, arrInstructions[1].opcode)) != NULL)
		{
			arrInstructions[1].f(&myStack, lineNo);
			lineNo--;
		}
		else if ((strstr(byteLine, arrInstructions[2].opcode)) != NULL)
		{
			arrInstructions[2].f(&myStack, lineNo);
			lineNo--;
		}
		else if ((strstr(byteLine, arrInstructions[3].opcode)) != NULL)
		{
			arrInstructions[3].f(&myStack, lineNo);
			lineNo--;
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>\n", lineNo);
			exit(EXIT_FAILURE);
		}

		lineNo++;
	}

	fclose(byteFile);
	free(myStack);
	return (0);
}
