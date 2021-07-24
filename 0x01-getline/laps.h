#ifndef _LAPS_H_
#define _LAPS_H_
#include <stdio.h>
#include <stdlib.h> /* malloc, free */

/**
 * struct car_s - struct of a car
 * @id: id of car
 * @lap: lap counter
 * @next: next node
 */
typedef struct car_s
{
	int id;
	int lap;
	struct car_s *next;
} car_t;

void race_state(int *id, size_t size);
car_t *car_add(car_t **head, int id);
void car_free(car_t *head);
car_t *get_car(car_t *head, int id);
void print_cars(car_t *head);

#endif /* _LAPS_H_ */
