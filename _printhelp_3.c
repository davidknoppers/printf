#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _revstr - print out a string in reverse
 * @c: va-list
 * @buffer: buffer to write to
 * @val: struct holding return vals
 * Return: new val
 */
sl_t _revstr(va_list c, char *buffer, sl_t val)
{
	int i, k;
	char *src, *temp;

	src = va_arg(c, char *);
	for (i = 0; src[i] != '\0'; i++)
		;
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (val);
	for (k = 0, i = i - 1; i >= 0; i--, k++)
		temp[k] = src[i];
	temp[k] = '\0';
	val = _strcpy(buffer, temp, val);
	free(temp);
	return (val);
}

/**
 * _rot13 - function to print out rot13 of a string
 * @c: va_list value
 * @buffer: buffer to write to
 * @val: struct holding values
 * Return: new val
 */
sl_t _rot13(va_list c, char *buffer, sl_t val)
{
	int i, k;
	char *src, *temp;

	src = va_arg(c, char *);
	for (i = 0; src[i] != '\0'; i++)
		;
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (val);
	for (k = 0; k < i; k++)
	{
		if ((src[k] >= 'a' && src[k] <= 'm') ||
		    (src[k] >= 'A' && src[k] <= 'M'))
			temp[k] = src[k] + 13;
		else if ((src[k] >= 'n' && src[k] <= 'z') ||
			 (src[k] >= 'N' && src[k] <= 'Z'))
			temp[k] = src[k] - 13;
		else
			temp[k] = src[k];
	}
	temp[k] = '\0';
	val = _strcpy(buffer, temp, val);
	free(temp);
	return (val);
}
