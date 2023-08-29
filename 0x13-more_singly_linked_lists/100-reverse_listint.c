#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *head;

	head = NULL;
	add_nodeint_end(&head, 0);
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 3);
	add_nodeint_end(&head, 4);
	add_nodeint_end(&head, 98);
	add_nodeint_end(&head, 402);
	add_nodeint_end(&head, 1024);

	printf("Original list:\n");
	print_listint(head);

	reverse_listint(&head);

	printf("Reversed list:\n");
	print_listint(head);

	free_listint2(&head);

	return (0);
}

/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to a pointer to the head of the list
 *
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

