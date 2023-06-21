#include "monty.h"

void sub(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, sum;

	h = *head;

	for (len = 0; h != NULL; len++)
		h = h->next;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	h = *head;
	sum = h->next->n - h->n;
	h->next->n = sum;
	*head = h->next;
	free(h);
}
/*
void div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, div;

        h = *head;

        for (len = 0; h != NULL; len++)
                h = h->next;
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", count);
                exit(EXIT_FAILURE);
        }
	if (h->n == 0)
	{
		fprintf(stderr, "L<line_number>: division by zero\n", count);
		exit(EXIT_FAILURE);
	}
	div = h->prev->n / h->n;
        h->next->n = div;
        *head = h->next;
        free(h);
}*/
