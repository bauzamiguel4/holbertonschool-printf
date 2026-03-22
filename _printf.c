#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - helper to print a char from va_list
 * @args: list of arguments
 *
 * Return: 1
 */
static int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str++);
					count++;
				}
			}
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
