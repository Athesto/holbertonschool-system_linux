/**
 * numlen - count num digits
 * @num: input number
 * Return: number of digits (-1 counts)
 */
int numlen(int num)
{
	int len = 1;

	if (num < 0)
	{
		num = -num;
		len++;
	}


	while (num > 1)
	{
		num /= 10;
		len++;
	}

	return (len);
}
