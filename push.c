#include "monty.h"
diff_t diff;
void push(stack_t **stack, unsigned int count)
{
        int n, j = 0, flag = 0;
        if (diff.arg == NULL)
        {
                fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(diff.fd);
                free(diff.cmd);
		exit(EXIT_FAILURE);
        }
        if (diff.arg[0] == '-')
                j++;
        for (; diff.arg[j] != '\0'; j++)
        {
                if (diff.arg[j] > 57 || diff.arg[j] < 48)
                        flag = 1;
        }
        if (flag == 1)
        {
                fprintf(stderr, "L%d: usage: push integer\n", count);
                fclose(diff.fd);
                free(diff.cmd);
		exit(EXIT_FAILURE);
        }

        n = atoi(diff.arg);
	if (diff.lifi == 0)
                add_dnodeint(stack, n);
        else
                addqueue(stack, n);
}
void pall(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *stack;
	if (h == NULL)
	{
		return;
	}
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
