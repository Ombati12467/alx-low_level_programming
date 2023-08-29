#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a linked list.
 * @head: Pointer to a pointer to the first node in the list.
 * @idx: Index where the new node is added (starting at 0).
 * @n: Data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if insertion failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
