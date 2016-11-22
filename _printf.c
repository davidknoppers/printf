#include "holberton.h"
#include <unistd.h>
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
	int i, j, z, num_of_formats, size;
	print_t c_or_str[] = {
		{"c", _printchar}, {"s", _printstring}, {"d", _printnum},
		{"i", _printnum}, {"u", _printunsign}, {"o", _printoct},
		{"x", _printhex}, {"X", _printhexUP}, {"b", _printbinary},
	};

	size = 0; temp = malloc(sizeof(char) * 2);
	num_of_formats = sizeof(c_or_str) / sizeof(print_t);
	for (i = 0; i < 1024; i++)
		buffer[i] = '\0';
	va_start(ap, format);
	if (format != NULL)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			z = 1;
			for (j = 0; j < num_of_formats; j++)
			{
				if (format[i] == '%' &&
				    format[i + 1] == *(c_or_str[j]).format_str)
				{
					size = c_or_str[j].f(ap, buffer, size);
					z = 0, i++;
					break;
				}
			}
			if (z != 0)
			{
				*temp = format[i];
				*(temp + 1) = '\0';
				size = _strcpy(buffer, temp, size);
			}
		}
	}
	free(temp);
	i = size + 1;
	_print_buffer(buffer, size);
	return (i);
}
