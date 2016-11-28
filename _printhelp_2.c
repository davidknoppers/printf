#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _oct - print out octal number
 * @c: argument
 * @buffer: buffer stuff
 * @val: size
 * Return: octal value
 */
sl_t _oct(va_list c, char *buffer, sl_t val)
{
	unsigned int k, j;
	char *temp;

	temp = malloc(sizeof(char) * 12);
	if (temp == NULL)
		return (val);
	j = va_arg(c, unsigned int);
	for (k = 0; j != 0; k++)
	{
		temp[k] = (j % 8) + '0';
		j = j / 8;
	}
	temp[k] = '\0';
	temp = rev_string(temp);
	val = _strcpy(buffer, temp, val);
	free(temp);
	return (val);
}

/**
 * _hex - print out hexadecimal
 * @c: argument
 * @buffer: buffer to write to
 * @val: length and size
 * Return: beginning of hex string
 */
sl_t _hex(va_list c, char *buffer, sl_t val)
{
	unsigned int i, dig, j, k;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'},
		{12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'},
	};

	k = va_arg(c, unsigned int);
	dig = k;
	temp = malloc(9 * sizeof(char));
	for (i = 0; k != 0; i++)
	{
		dig = k % 16;
		for (j = 0; j < 16; j++)
			if (dig == conv[j].dec)
				temp[i] = conv[j].hex;
		k = k / 16;
	}
	temp[i] = '\0';
	temp = rev_string(temp);
	val = _strcpy(buffer, temp, val);
	free(temp);
	return (val);
}

/**
 * _hexUP - print upper case
 * @c: argument
 * @buffer: buffer to print to
 * @val: length and size
 * Return: hex string
 */
sl_t _hexUP(va_list c, char *buffer, sl_t val)
{
	unsigned int i, j, k, dig;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'},
		{12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'},
	};

	k = va_arg(c, unsigned int);
	dig = k;
	temp = malloc(9 * sizeof(char));
	for (i = 0; k != 0; i++)
	{
		dig = k % 16;
		for (j = 0; j < 16; j++)
			if (dig == conv[j].dec)
				temp[i] = conv[j].hex;
		k = k / 16;
	}
	temp[i] = '\0';
	temp = rev_string(temp);
	val = _strcpy(buffer, temp, val);
	free(temp);
	return (val);
}

/**
 * _bi - print out binary code
 * @c: input
 * @buffer: buffer to print to
 * @val: value
 * Return: length
 */
sl_t _bi(va_list c, char *buffer, sl_t val)
{
	unsigned int i, j;
	char *str;

	j = 0;
	str = malloc(sizeof(char) * 33);
	i = va_arg(c, unsigned int);
	while (i != 0)
	{
		str[j] = (i % 2) + '0';
		i = i / 2;
		j++;
	}
	str[j] = '\0';
	str = rev_string(str);
	val = _strcpy(buffer, str, val);
	free(str);
	return (val);
}
