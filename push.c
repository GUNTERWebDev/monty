#include "monty.h"

stack_t  *add_TOS(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
		tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (stack != NULL && (*stack))
	{
		(*stack)->prev = tmp;
		tmp->next = *(stack);
	}
	if (stack != NULL)
		*(stack) = tmp;
	return (tmp);
}
stack_t *add_queue(stack_t **stack, int n)
{
	stack_t *new_e, *node;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new_e;
		new_e->prev = node;
	}

	return (new_e);
}
