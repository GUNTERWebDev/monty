#include "monty.h"

void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
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
