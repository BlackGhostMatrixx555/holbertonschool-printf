#include "main.h"

/**
 * get_handler - Returns the handler function for a given specifier
 * @spec: the conversion specifier character
 *
 * Return: pointer to the matching handler, or NULL if not found
 */
static int (*get_handler(char spec))(va_list)
{
	int i;
	fmt_t handlers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{0, NULL}
	};

	for (i = 0; handlers[i].fn != NULL; i++)
	{
		if (handlers[i].spec == spec)
			return (handlers[i].fn);
	}
	return (NULL);
}

/**
 * _printf - Produces output to stdout according to a format string
 * @format: character string with directives
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;
	int (*fn)(va_list);

	if (!format)
		return (-1);

	va_start(args, format);
	count = 0;
	i = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			i++;
			continue;
		}
		i++;
		if (!format[i])
		{
			va_end(args);
			return (-1);
		}

		fn = get_handler(format[i]);
		if (fn)
		{
			count += fn(args);
		}
		else
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			count += 2;
		}
		i++;
	}

	va_end(args);
	return (count);
}
