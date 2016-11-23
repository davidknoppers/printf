#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>

/**
 * percent - help print out percent signs
 * @f: lol
 * @i: omg
 * @buffer: the buffer
 * @val: num to pass around
 * Return: val
 */
sl_t percent(const char *f, int i, char *buffer, sl_t val)
{
	int j, percent;
	char *temp, *holder;

	percent = 1;
	for (j = i; (f[j] == '%' || f[j] == ' ') && f[j] != '\0'; j++)
		;
	temp = malloc(sizeof(char) * (j + 1));
	if (temp == NULL)
		return (val);
	holder = temp;
	for (j = i; (f[j] == '%' || f[j] == ' ') && f[j] != '\0'; j++)
	{
		if (f[j] == '%')
		{
			if (percent > 0)
			{
				*holder = '%';
				holder++;
				percent *= -1;
			}
			else
				percent *= -1;
		}
		else
		{
			while (f[j + 1] == ' ')
				j++;
			if (*(holder - 1) != ' ')
			{
				*holder = ' ';
				holder++;
			}
		}
	}
	*holder = '\0';
	val = _strcpy(buffer, temp, val);
	val.skip = j;
	free(temp);
	return (val);
}
