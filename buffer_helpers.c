#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _strcpy - copies and returns a string; triggers print when buffer is full
 * @buffer: destination string, output
 * @src: string to be copied
 * @size: size of current buffer
 * Return: dest
 */
int _strcpy(char *buffer, char *src, int size)
{
	int n;

	n = 0;
	while (src[n] != '\0')
	{
		buffer[size] = src[n];
		n++;
		size++;
		if (size >= 1023)
			size = _print_buffer(buffer, size);
	}
	return (size);
}

/**
 * _print_buffer - print out entire buffer
 * @buffer: destination string, output
 * @size: size of current buffer
 * Return: size
 */
int _print_buffer(char *buffer, int size)
{
	int i;

	write(1, buffer, size);
	for (i = 0; i < 1024; i++)
		buffer[i] = '\0';
	size = 0;
	return (size);
}
