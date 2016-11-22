#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _char - print out character
 * @c: input
 * @buffer: buffer
 * @val: position in buffer
 * Return: length 1
 */
sl_t _char(va_list c, char *buffer, sl_t val)
{
	char *j;

	j = malloc(sizeof(char) * 2);
	*j = va_arg(c, int);
	*(j + 1) = '\0';
	val = _charcpy(buffer, j, val);
	free (j);
	return (val);
}

/**
 * _str - print out string
 * @c: input
 * @buffer: buffer
 * @val: position in buffer
 * Return: length of string
 */
sl_t _str(va_list c, char *buffer, sl_t val)
{
	char *temp;
	char nil[8] = {'(', 'n', 'u', 'l', 'l', ')', '\0'};

	temp = va_arg(c, char *);
	if (temp == NULL)
	{
		val = _strcpy(buffer, nil, val);
		return (val);
	}
	val = _strcpy(buffer, temp, val);
	return (val);
}

/**
 * _num - print out number
 * @c: input
 * @buffer: buffer
 * @val: size
 * Return: length of num
 */
sl_t _num(va_list c, char *buffer, sl_t val)
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
		return (val);
	for (j = 0; j < i; j++)
	{
		num[j] = (m % 10) * (-1) + '0';
		m = m / 10;
	}
	if (s == 1)
		val = _strcpy(buffer, sign, val);
	num[j] = '\0';
	num = rev_string(num);
	val = _strcpy(buffer, num, val);
	free(num);
	free(sign);
	return (val);
}

/**
 * _unsign - print unsigned nums
 * @c: input
 * @buffer: buffer
 * @val: lol
 * Return: length of num
 */
sl_t _unsign(va_list c, char *buffer, sl_t val)
{
	unsigned int m, i, j;
	char *num;

	m = va_arg(c, unsigned int);
	j = m;
	for (i = 0; j > 0; i++)
		j = j / 10;
	num = malloc((i + 1) * sizeof(char));
	if (num == NULL)
		return (val);
	for (j = 0; j < i; j++)
	{
		num[j] = m % 10 + '0';
		m = m / 10;
	}
	num[j] = '\0';
	num = rev_string(num);
	val = _strcpy(buffer, num, val);
	free(num);
	return (val);
}

/**
 * _percent - print only one percent sign
 * @c: input
 * @buffer: buffer to print to
 * @val: location in buff
 * Return: size
 */
sl_t _percent(va_list c, char *buffer, sl_t val)
{
	char *percent;

	percent = malloc(sizeof(char) * 2);
	if (percent == NULL)
		return (val);
	*percent = va_arg(c, int);
	*percent = '%';
	*(percent + 1) = '\0';
	val = _strcpy(buffer, percent, val);
	free(percent);
	return (val);
}
