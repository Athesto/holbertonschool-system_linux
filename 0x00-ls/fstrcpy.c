/**
 * _strcpy - copy src to dst
 * @dst: output
 * @src: input
 * Return: dst
 */
char *_strcpy(char *dst, char *src)
{
	int i = 0;

	do {
		dst[i] = src[i];
	} while (src[i++]);

	return (dst);
}
