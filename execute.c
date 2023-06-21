#include "monty.h"
/**
 * execute - execute the cmd command and calls functions
 * @cmd: command
 * @count: count
 * @stack: stack
 * @fd: file descriptor
 *
 * Return: void
 */
void execute(char *cmd, unsigned int count, stack_t **stack, FILE *fd, diff_t diff)
{
	instruction_t lists[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(cmd, " \n\t");
	if (op && op[0] == '#')
	{
		return;
	}
	diff.arg = strtok(NULL, " \n\t");
	while (lists[i].opcode && op)
	{
		if (strcmp(op, lists[i].opcode) == 0)
		{
			lists[i].f(stack, count, diff);
			return;
		}
		i++;
	}
	if (op && lists[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(fd);
		free(cmd);
		exit(EXIT_FAILURE);
	}
}
