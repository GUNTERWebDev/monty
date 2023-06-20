#include "monty.h"

void read_monty(FILE *fd)
{
	char *cmd = NULL;
	size_t len = 0;
	size_t cmd_len;
	stack_t *stack = NULL;
	unsigned int count = 0;
	cmd_len = getline(&cmd, &len, fd);
	while (cmd_len != 0)
	{
		execute(&cmd, count, &stack, fd);
		count++;
	}
	free(cmd);
}
