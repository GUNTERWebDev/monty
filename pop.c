#include "monty.h"
void pop(stack_t **head, unsigned int count)
{
	stack_t *next;

	if (*head == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}

	next = (*head)->next;
	free(*head);
	(*head) = next;
	if (next)
		next = next->next;
}
