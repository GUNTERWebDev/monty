#include "monty.h"
void f_div(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
              fprintf(stderr, "L%d: division by zero\n", count);
              exit(EXIT_FAILURE);
        }
	h->next->n /= h->n;
	*head = h->next;
	free(h);
}
