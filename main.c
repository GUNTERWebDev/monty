#include "monty.h"
diff_t diff = {NULL, NULL, NULL, 0};
/**
 * main - main
 * @ac: count
 * @av: vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	char *cmd;
	size_t len;
	ssize_t cmd_len;
	stack_t *stack = NULL;
	unsigned int count;

	len = 0;
	cmd_len = 1;
	count = 0;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	diff.fd = fd;
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (cmd_len > 0)
	{
		cmd = NULL;
		cmd_len = getline(&cmd, &len, fd);
		diff.cmd = cmd;
		count++;
		if (cmd_len > 0)
			execute(cmd, count, &stack, fd);
		free(cmd);
	}
	free_stack(stack);
	fclose(fd);
	return (0);
}
