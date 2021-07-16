/**
 * _strcmp - compare 2 str
 * @a: input1
 * @b: input2
 * Return: an integer as a-b
 */
int _strcmp(char *a, char *b)
{
	int diff;

	while ((diff = *a - *b) == 0 && *a && *b)
	{
		a++;
		b++;
	}

	return (diff);
}
