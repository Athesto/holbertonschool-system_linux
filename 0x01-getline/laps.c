#include "laps.h"

/**
 * race_state - race_states
 * @id: array of car's id
 * @size: size of this array
 *
 */
void race_state(int *id, size_t size)
{
	static car_t *head;
	car_t *node;
	size_t i;


	if (size == 0)
	{
		free_list(head);
		return;
	}


	for (i = 0; i < size; i++)
	{
		node = find_node(head, id[i]);
		if (node == NULL)
		{
			node = add_node(&head, id[i]);
			printf("Car %d joined the race\n", node->id);
		}
		else
		{
			(node->lap)++;
		}
	}
	printRaceState(head);
}

/**
 * printRaceState - print the linked list
 * @head: list of cars
 */
void printRaceState(car_t *head)
{
	printf("Race state:\n");
	while (head)
	{
		printf("Car %d [%d laps]\n", head->id, head->lap);
		head = head->next;
	}
}

/**
 * find_node - check if the id is registered in the list
 * @head: linked list
 * @id: id of the car
 * Return: node of index, or NULL if it fails
 */
car_t *find_node(car_t *head, int id)
{
	while (head && head->id != id)
		head = head->next;
	return (head);
}

/**
 * add_node - add node to the element
 * @head: head of linked list
 * @id: id of the element
 * Return: node of the new node or null if it fails
 */
car_t *add_node(car_t **head, int id)
{
	car_t *node;
	car_t *runner;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->id = id;
	node->lap = 0;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	for (runner = *head; runner; runner = runner->next)
	{
		if (runner->id <= id)
		{
			if (runner->next == NULL || runner->next->id > id)
			{
				node->next = runner->next;
				runner->next = node;
				break;
			}
		}
	}
	return (node);
}

/**
 * free_list - free linked list
 * @head: head of linked list
 */
void free_list(car_t *head)
{
	car_t *killer;

	while (head)
	{
		killer = head;
		head = head->next;
		free(killer);
	}
}
