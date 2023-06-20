#include "monty.h"
diff_t diff = {NULL, NULL, NULL, 0};
int main(int ac, char **av)
{
	FILE *fd;
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
	read_monty(fd);
	fclose(fd);
	return (0);
}
