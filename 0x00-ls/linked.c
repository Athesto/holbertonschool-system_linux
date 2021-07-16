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
	new->next = NULL;

	va_start(args, type);
	if (type == DIR_ENTRY)
		new->entry = va_arg(args, struct dirent *);
	else if (type == ARGS)
		new->name = va_arg(args, char *);
	va_end(args);


	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	runner = *head;
	while (runner->next)
	{
		runner = runner->next;
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
	if (head)
		list_free(head->next);
	free(head);
}
