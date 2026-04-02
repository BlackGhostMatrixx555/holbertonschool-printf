#include "main.h"

/**
 * print_char - Prints a single character
 * @args: va_list pointing to the char argument
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a null-terminated string
 * @args: va_list pointing to the char * argument
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	len = 0;
	while (str[len])
		len++;

	write(1, str, len);
	return (len);
}

/**
 * print_percent - Prints a literal percent sign
 * @args: va_list (unused)
 *
 * Return: always 1
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * print_int - Prints a signed integer in base 10
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
