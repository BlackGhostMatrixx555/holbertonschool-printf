#include "main.h"

/**
 * print_char - Prints a single character to stdout
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
