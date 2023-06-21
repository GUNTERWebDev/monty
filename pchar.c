#include "monty.h"
void pchar(stack_t **head, unsigned int count)
{
        stack_t *h;

        h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		 exit(EXIT_FAILURE);
	}
	if (h->n >= 0 && h->n <= 127)
	{
		printf("%c\n", h->n);
	}
	else
	{
                fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
                exit(EXIT_FAILURE);
        }
}
