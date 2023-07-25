#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int j, i, count;
	va_list args;

	op_t type[] = {
		{"c", print_c}, {"s", print_s}, {"%", print_percent},
		{"d", print_d}, {"i", print_i}, {'\0', NULL}
	};
	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	i = 0, count = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			j = 0;
			while (type[j].op && format[i] != *(type[j].op))
				j++;
			if (type[j].op)
			{
				type[j].f(args);
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
