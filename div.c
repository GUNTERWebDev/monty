#include "monty.h"
void f_div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, div;

	h = *head;

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
	if (h->n == 0)
	{
              fprintf(stderr, "L%d: division by zero\n", count);
              exit(EXIT_FAILURE);
        }
	div = h->n / h->next->n;
	h->next->n = div;
	*head = h->next;
	free(h);
}
