#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list, even if it contains a loop.
 * @h: A pointer to the pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (!h)
		return (0);

	current = *h;
	while (current)
	{
		count++;
		temp = current;
		current = current->next;

		/* Check if the current node has been visited before */
		if ((temp - current) > 0)
			free(temp);
		else
		{
			*h = NULL;
			break;
		}
	}

	return (count);
}

