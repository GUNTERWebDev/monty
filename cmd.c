#include "monty.h"
stack_t  *add_dnodeint(stack_t  **head, const int n)
{
	stack_t *tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (head && (*head))
	{
		(*head)->prev = tmp;
		tmp->next = *(head);
	}
	if (head != NULL)
		*(head) = tmp;
	return (tmp);
}
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
