#ifndef _LAPS_H_
#define _LAPS_H_
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

void race_state(int *, size_t);

/**
 * struct node_car - node for a linked list
 * @id: id of the car
 * @lap: lap number
 * @next: linked list
 */
typedef struct node_car
{
	int id;
	int lap;
	struct node_car *next;
} car_t;

void printRaceState(car_t *);
car_t *find_node(car_t *, int);
car_t *add_node(car_t **, int);
void free_list(car_t *);



#endif /* _LAPS_H_ */
