#include "monty.h"

void execute(char *cmd, unsigned int count, stack_t *stack, FILE *fd)
{
	instruction_t lists[] = {
		{"swap", swap}, {"push", push},
		{"pall", pall}, {"pop", pop},
		{"add", add}, {"sub", sub},
		{"mul", mul}, {"pint", pint},
		{"div", divide},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(cmd, " \n\t");
	if (op && op[0] == "#")
		return (0);
	while (lists[i].opcode && op)
	{
		if (strcmp(op, lists[i].opcode) == 0)
		{
			lists[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && lists[i].opcode)
	{
		fprintf(stderr, "L%s: unknown instruction %s\n", count, op);
		exit(EXIT_FAILURE);
	}
