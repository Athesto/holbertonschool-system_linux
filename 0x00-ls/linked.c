#include "hls.h"
/**
 * list_append - append into the linked list
 * @head: reference to head of linked list
 * @type: select if the lis is an DIR_ENTRY or ARGS
 * Return: pointer to the new node
 */
linked_t *list_append(linked_t **head, int type, ...)
{
	linked_t *new, *runner;
	va_list args;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->parent = NULL;
	new->name = NULL;
	new->entry = NULL;
	new->next = NULL;

	va_start(args, type);
	new->name = va_arg(args, char *);
	if (type == DIR_ENTRY)
	{
		new->parent = va_arg(args, char *);
		new->entry = va_arg(args, struct dirent *);
	}
	va_end(args);


	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	for (runner = *head; runner->next; runner = runner->next)
	{
		;
	}

	runner->next = new;

	return (new);
}

/**
 * list_free - free list
 * @head: head of list
 */
void list_free(linked_t *head)
{
	linked_t *killer;

	killer = head;
	for (killer = head; head; free(killer))
	{
		killer = head;
		head = head->next;
	}
}
