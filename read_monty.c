#include "monty.h"

void read_monty(FILE *fd)
{
	char *cmd;
	size_t len = 0;
	ssize_t cmd_len = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;
	
	while (cmd_len > 0)
	{
		cmd = NULL;
		cmd_len = getline(&cmd, &len, fd);
		diff.cmd = cmd;
		count++;
		if (cmd_len > 0)
			execute(cmd, count, stack, fd);
		free(cmd);
	}
	free_stack(stack);
	fclose(fd);
}
