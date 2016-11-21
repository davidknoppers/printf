#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printoct - print out octal number
 * @c: argument
 * Return: octal value
 */
int _printoct(va_list c)
{
	int oct, i, j;

	oct = 0;
	i = 1;
	j = va_arg(c, int);
	while (j != 0)
	{
		oct += (j % 8) * i;
		j = j / 8;
		i = 10 * i;
	}

	return (oct);
}

/**
 * _printhex - print out hexadecimal
 * @c: argument
 * Return: beginning of hex string
 */
int _printhex(va_list c)
{
	int i, j, dig, k, z;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'},
		{12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'},
	};

	k = va_arg(c, int);
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
 * _printhexUP - print upper case
 * @c: argument
 * Return: hex string
 */
int _printhexUP(va_list c)
{
	int i, j, dig, k, z;
	char *temp;
	hex_t conv[] = {
		{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
		{4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
		{8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'},
		{12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'},
	};

	k = va_arg(c, int);
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
 * _printbinary - print out binary code
 * @c: input
 * Return: length
 */
int _printbinary(va_list c)
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
