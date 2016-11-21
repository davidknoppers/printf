#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printchar - print out character
 * @c: input
 * @buffer: buffer
 * @size: position in buffer
 * Return: length 1
 */
int _printchar(va_list c, char *buffer, int size)
{
	char *j;

	j = va_arg(c, char *);
	if (j == NULL)
		return (0);
	size = _strcpy(buffer, j, size);
	return (size);
}

/**
 * _printstring - print out string
 * @c: input
 * @buffer: buffer
 * @size: position in buffer
 * Return: length of string
 */
int _printstring(va_list c, char *buffer, int size)
{
	char *temp;

	temp = va_arg(c, char *);
	if (temp == NULL)
		return (0);
	size = _strcpy(buffer, temp, size);
	return (size);
}

/**
 * _printnum - print out number
 * @c: input
 * @buffer: buffer
 * @size: size
 * Return: length of num
 */
int _printnum(va_list c, char *buffer, int size)
{
	int m, i, j;
	char *num;
	char sign;

	sign = '-';
	m = va_arg(c, int);
	j = m;
	for (i = 0; j > 0; i++)
		j = j / 10;
	num = malloc((i + 1) * sizeof(char));
	if (num == NULL)
		return (size);
	if (m < 0)
	{
		m = m * -1;
		size = _strcpy(buffer, &sign, size);
	}
	for (j = 0; j < i; j++)
	{
		num[j] = m % 10 + '0';
		m = m / 10;
	}
	num[j] = '\0';
	num = rev_string(num);
	size = _strcpy(buffer, num, size);
	free(num);
	return (size);
}

/**
 * _printunsign - print unsigned nums
 * @c: input
 * @buffer: buffer
 * @size: lol
 * Return: length of num
 */
int _printunsign(va_list c, char *buffer, int size)
{
	unsigned int m, i, j;
	char *num;

	m = va_arg(c, unsigned int);
	j = m;
	for (i = 0; j > 0; i++)
		j = j / 10;
	num = malloc((i + 1) * sizeof(char));
	if (num == NULL)
		return (size);
	for (j = 0; j < i; j++)
	{
		num[j] = m % 10 + '0';
		m = m / 10;
	}
	num[j] = '\0';
	num = rev_string(num);
	size = _strcpy(buffer, num, size);
	free(num);
	return (size);
}
