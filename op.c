#include "monty.h"

void sub(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, sum;

	h = *head;

	if (h == NULL)
       {
                fprintf(stderr, "L%d: can't add, stack too short\n", count);
                exit(EXIT_FAILURE);
        }
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	h = *head;
	sum = h->next->n - h->n;
	h->next->n = sum;
	*head = h->next;
	free(h);
}
