#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - main print functions
 * @format: format string
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char buffer[1024], *temp;
	int i, j, z, num_of_formats, size, yes;
	print_t c_or_str[] = {
		{"c", _char}, {"s", _str}, {"d", _num}, {"i", _num},
		{"u", _unsign}, {"o", _oct}, {"x", _hex}, {"X", _hexUP},
		{"b", _bi}, {"%", _percent},
	};
	sl_t vals = {0, 0};

	yes = 1; temp = malloc(sizeof(char) * 2);
	num_of_formats = sizeof(c_or_str) / sizeof(print_t);
	for (i = 0; i < 1024; i++)
		buffer[i] = '\0';
	va_start(ap, format);
	if (format != NULL)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			for (z = 1, j = 0; j < num_of_formats; j++)
			{
				if (format[i] == '%' &&
				    format[i + 1] == *(c_or_str[j]).format_str)
				{
					vals = c_or_str[j].f(ap, buffer, vals);
					z = 0; i++; break;
				}
			}
			if (z != 0)
			{
				*temp = format[i]; *(temp + 1) = '\0';
				if ((*temp == '%' && yes > 0) || *temp != '%')
					vals = _strcpy(buffer, temp, vals);
				if (*temp == '%')
					yes = yes * -1;
			}
		}
	}
	free(temp); _print_buffer(buffer, vals); size = vals.len;
	return (size);
}
