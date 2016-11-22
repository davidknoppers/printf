#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _oct - print out octal number
 * @c: argument
 * @buffer: buffer stuff
 * @size: size
 * Return: octal value
 */
int _oct(va_list c, char *buffer, int size)
{
	unsigned int k, j;
	char *temp;

	temp = malloc(sizeof(char) * 12);
	if (temp == NULL)
		return (size);
	j = va_arg(c, unsigned int);
	for (k = 0; j != 0; k++)
	{
		temp[k] = (j % 8) + '0';
		j = j / 8;
	}
	temp[k] = '\0';
	temp = rev_string(temp);
	size = _strcpy(buffer, temp, size);
	return (size);
}

/**
 * _hex - print out hexadecimal
 * @c: argument
 * Return: beginning of hex string
 */
int _hex(va_list c)
{
	unsigned int i, j, dig, k, z;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'},
		{12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'},
	};

	k = va_arg(c, unsigned int);
	dig = k;
	for (i = 0; k / 10 > 0; i++)
		k = k / 10;
	z = i;
	k = dig;
	temp = malloc((i + 1) * sizeof(char));
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
	_puts(temp);
	return (z);
}

/**
 * _hexUP - print upper case
 * @c: argument
 * Return: hex string
 */
int _hexUP(va_list c)
{
	unsigned int i, j, dig, k, z;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'},
		{12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'},
	};

	k = va_arg(c, unsigned int);
	dig = k;
	for (i = 0; k / 10 > 0; i++)
		k = k / 10;
	z = i;
	k = dig;
	temp = malloc((i + 1) * sizeof(char));
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
	_puts(temp);
	return (z);
}

/**
 * _bi - print out binary code
 * @c: input
 * Return: length
 */
int _bi(va_list c)
{
	int i, j;
	char *str;

	j = 0;
	str = malloc(sizeof(char) * 33);
	i = va_arg(c, int);
	while (i != 0)
	{
		str[j] = (i % 2) + '0';
		i = i / 2;
		j++;
	}
	str[j] = '\0';
	str = rev_string(str);
	_puts(str);
	free(str);
	return (j);
}
