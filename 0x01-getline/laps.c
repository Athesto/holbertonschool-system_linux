#include "laps.h"

/**
 * race_state - example of race
 * @id: array of int representing the “identifier” of each car.
 * @size: size of array
 */
void race_state(int *id, size_t size)
{
	size_t i;
	static car_t *head;
	car_t *car;

	if (size == 0)
	{
		car_free(head);
		return;
	}

	for (i = 0; i < size; i++)
	{
		car = get_car(head, id[i]);
		if (car)
		{
			car->lap++;
		}
		else
		{
			car_add(&head, id[i]);
			printf("Car %d joined the race\n", id[i]);
		}
	}
	print_cars(head);
}

/**
 * print_cars - state of cars
 * @head: list of cars
 */
void print_cars(car_t *head)
{
	car_t *runner;

	printf("Race state:\n");
	for (runner = head; runner; runner = runner->next)
		printf("Car %d [%d laps]\n", runner->id, runner->lap);
}

/**
 * get_car - search car in list
 * @head: car list
 * @id: searching pattern
 * Return: pointer to car if found, NULL otherwise
 */
car_t *get_car(car_t *head, int id)
{
	car_t *runner;

	for (runner = head; runner; runner = runner->next)
		if (runner->id == id)
			break;

	return (runner);
}

/**
 * car_add - simple append to a linked list
 * @head: reference to a linked list
 * @id: input id
 * Return: pointer to new car
 */
car_t *car_add(car_t **head, int id)
{
	car_t *new, *runner;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->id = id;
	new->lap = 0;
	new->next = NULL;

	if (*head == NULL || (*head)->id > id)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	runner = *head;
	while (runner->next)
	{
		if (runner->next->id >= id)
		{
			new->next = runner->next;
			break;
		}
		runner = runner->next;
	}

	runner->next = new;

	return (new);
}

/**
 * car_free - free list
 * @head: list
 */
void car_free(car_t *head)
{
	if (!head)
		return;
	car_free(head->next);
	free(head);
}



