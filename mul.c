#include "monty.h"
void mul(stack_t **head, unsigned int count)
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
                fprintf(stderr, "L%d: can't mul, stack too short\n", count);
                exit(EXIT_FAILURE);
        }
        h = *head;
        h->next->n *= h->n;
        *head = h->next;
        free(h);
}

