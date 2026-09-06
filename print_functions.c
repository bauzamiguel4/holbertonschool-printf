#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s;
	int i;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}

	return (i);
}

/**
 * print_percent - prints a percent sign
 * @args: list of arguments (unused)
 *
 * Return: number of characters printed (always 1)
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_int - prints an integer (for %d and %i)
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	unsigned int div = 1;

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div != 0)
	{
		count += _putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}

	return (count);
}
