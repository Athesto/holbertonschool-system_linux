#include "../laps.h"

void test_0();
/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main()
{
	test_0();

	return (0);
}


void test_0()
{
	int ids1[3] = {1, 42, 101};
	int ids2[1] = {11};

	race_state(ids1, 3);
	printf("--\n");
	race_state(ids1, 3);
	printf("--\n");
	race_state(ids1, 3);
	printf("--\n");
	race_state(ids2, 1);
	printf("--\n");
	race_state(ids1, 3);
	printf("--\n");
	race_state(ids2, 1);
	printf("--\n");
	race_state(ids1, 3);
	printf("--\n");
	race_state(ids2, 1);
	printf("--\n");
	race_state(ids1, 3);
	printf("--\n");
	race_state(ids2, 1);
	printf("--\n");
	race_state(NULL, 0);
}
