#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _char - print out character
 * @c: input
 * @buffer: buffer
 * @size: position in buffer
 * Return: length 1
 */
int _char(va_list c, char *buffer, int size)
{
	char *j;

	j = malloc(sizeof(char) * 2);
	*j = va_arg(c, int);
	*(j + 1) = '\0';
	size = _strcpy(buffer, j, size);
	return (size);
}

/**
 * _str - print out string
 * @c: input
 * @buffer: buffer
 * @size: position in buffer
 * Return: length of string
 */
int _str(va_list c, char *buffer, int size)
{
	char *temp;
	char *nil;

	nil = malloc(sizeof(char) * 7);
	if (nil == NULL)
		return (size);
	nil = "(null)";
	temp = va_arg(c, char *);
	if (temp == NULL)
	{
		size = _strcpy(buffer, nil, size);
		return (size);
	}
	size = _strcpy(buffer, temp, size);
	return (size);
}

/**
 * _num - print out number
 * @c: input
 * @buffer: buffer
 * @size: size
 * Return: length of num
 */
int _num(va_list c, char *buffer, int size)
{
	int m, j, i, s;
	char *num;
	char *sign;

	sign = malloc(sizeof(char) * 2);
	*sign = '-';
	*(sign + 1) = '\0';
	s = 1;
	m = va_arg(c, int);
	if (m >= 0)
	{
		s = 0;
		m = m * -1;
	}
	j = m;
	if (j == 0)
		i = 1;
	else
	{
		for (i = 0; j != 0; i++)
			j = j / 10;
	}
	num = malloc((i + 1) * sizeof(char));
	if (num == NULL)
		return (size);
	for (j = 0; j < i; j++)
	{
		num[j] = (m % 10) * (-1) + '0';
		m = m / 10;
	}
	if (s == 1)
		size = _strcpy(buffer, sign, size);
	num[j] = '\0';
	num = rev_string(num);
	size = _strcpy(buffer, num, size);
	free(num);
	free(sign);
	return (size);
}

/**
 * _unsign - print unsigned nums
 * @c: input
 * @buffer: buffer
 * @size: lol
 * Return: length of num
 */
int _unsign(va_list c, char *buffer, int size)
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

/**
 * _percent - print only one percent sign
 * @c: input
 * @buffer: buffer to print to
 * @size: location in buff
 * Return: size
 */
int _percent(va_list c, char *buffer, int size)
{
	char *percent;

	percent = malloc(sizeof(char) * 2);
	*percent = va_arg(c, int);
	*percent = '%';
	*(percent + 1) = '\0';
	size = _strcpy(buffer, percent, size);
	free(percent);
	return (size);
}
