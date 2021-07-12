#include <unistd.h>
int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		write(1, &c, 1);
	return (0);
}


