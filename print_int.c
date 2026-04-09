#include "main.h"

/**
 * print_int - Prints a signed integer in base 10 to stdout
 * @args: va_list pointing to the int argument
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	int count;
	int divisor;
	int digit;
	char c;

	n = va_arg(args, int);
	count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
	}

	divisor = 1;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return (count + 10);
	}

	if (n < 0)
		n = -n;

	while (n / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = (n / divisor) % 10;
		c = '0' + digit;
		write(1, &c, 1);
		count++;
		divisor /= 10;
	}

	return (count);
}
