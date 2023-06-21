#include "monty.h"
void rotl(stack_t **head, unsigned int count)
{
	stack_t *tmp, *aux;

	(void)count;
	tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
