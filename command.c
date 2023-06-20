#include "monty.h"

void push(stack_t **stack, unsigned int count)
{
	int n;
	char *s, *check;

	check = "";
	s = strtok(NULL, "\t\n ");
	if (s && check)
		n = atoi(s);
	if (!s || *check != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL && (*stack))
		add_TOS(stack, n);
	else
		add_queue(stack, n);
}
