#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * Does not handle all edge cases of % signs
 */

/**
 * perc_parse - parse % strs to make sure it still works
 * @f: format string
 * @i: position in format string
 * @buffer: buffer to write to
 * @val: struct holding buffer values
 * Return: val
 */
sl_t perc_parse(const char *f, int i, char *buffer, sl_t val)
{
	char *temp, *holder;
	int j, k, b, perc;

	for (j = i, k = 0; f[j] != '\0' && (f[j] == '%' || f[j] == ' '); j++, k++)
		;
	temp = malloc(sizeof(char) * (k + 1));
	holder = temp;
	for (i = i, perc = 1, b = 0; b < k; i++, b++, val.i++)
	{
		if (f[i] == '%' && perc > 0)
		{
			*temp = f[i];
			perc *= -1;
			temp++;
		}
		else if (f[i] == '%')
		{
			perc *= -1;
			if (f[i + 1] == ' ')
			{
				while (f[i + 1] == ' ')
					i++, val.i++;
			}
		}
		else
		{
			*temp = f[i];
			temp++;
		}
	}
	*temp = '\0';
	val = _strcpy(buffer, holder, val);
	free(holder);
	return (val);
}

/**
 * space_parse - function initially needed to parse spaces, NOT IN USE
 * @src: src string to parse
 * Return: new string
 */
char *space_parse(char *src)
{
	int i;
	char *temp, *holder;

	for (i = 0; src[i] != '\0'; i++)
		;
	temp = malloc(sizeof(char) * (i + 1));
	holder = temp;
	for (i = 0; src[i] != '\0'; i++)
	{
		if (src[i] == ' ')
		{
			if (*(temp - 1) != ' ')
			{
				*temp = ' ';
				temp++;
			}
		}
		else
		{
			*temp = src[i];
			temp++;
		}
	}
	return (holder);
}
