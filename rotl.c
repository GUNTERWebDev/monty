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
void rotr(stack_t **head, unsigned int count)
{
        stack_t *tmp;

        (void)count;
        tmp = *head;
        if (*head == NULL || (*head)->next == NULL)
        {
                return;
        }
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
	tmp->next = *head;
	tmp->prev->next = NULL;
        tmp->prev = NULL;
        (*head)->prev = tmp;
        (*head) = tmp;
}

