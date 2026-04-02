#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct fmt_s - Associates a format specifier with its handler
 * @spec: the conversion specifier character (e.g. 'c', 's', 'd')
 * @fn: pointer to the function that handles this specifier
 */
typedef struct fmt_s
{
	char spec;
	int (*fn)(va_list);
} fmt_t;

/* Main printf function */
int _printf(const char *format, ...);

/* Handlers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif /* MAIN_H */
