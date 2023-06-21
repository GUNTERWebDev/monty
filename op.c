#include "monty.h"

void sub(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = (*head)->next;
	h->n -= (*head)->n;
	pop(head, count);
}
