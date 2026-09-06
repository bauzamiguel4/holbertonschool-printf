#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing characters and specifiers
 *
 * Return: number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += print_percent(args);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
