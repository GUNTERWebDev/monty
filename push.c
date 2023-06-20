#include "monty.h"

void push(stack_t *stack, unsigned int n)
{
	dlistint_t *tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (stack && (*stack))
	{
		(*stack)->prev = tmp;
		tmp->next = *(stack);
	}
	if (stack != NULL)
		*(stack) = tmp;
	return (tmp);
}
