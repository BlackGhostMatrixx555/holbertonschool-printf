#include "main.h"

/**
 * print_string - Prints a null-terminated string to stdout
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
