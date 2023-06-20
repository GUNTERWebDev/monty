#include "monty.h"

void execute(char *cmd, unsigned int count, stack_t *stack, FILE *fd)
{
	instruction_t lists[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(cmd, " \n\t");
	while (lists[i].opcode && op)
	{
		if (strcmp(op, lists[i].opcode) == 0)
		{
			lists[i].f(&stack, count); 
		}
		i++;
	}
	if (op == NULL && lists[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(fd);
		free(cmd);
		exit(EXIT_FAILURE);
	}
}
