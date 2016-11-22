#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _charcpy - copy a character
 * @buffer: buffer to write to
 * @src: src copy
 * @val: struct
 * Return: val
 */
sl_t _charcpy(char *buffer, char *src, sl_t val)
{
	int n;

	n = 0;
	if (src[0] == '\0')
	{
		buffer[val.size] = src[0];
		val.size++;
		val.len++;
		return (val);
	}
	while (src[n] != '\0')
	{
		buffer[val.size] = src[n];
		n++;
		val.size++;
		val.len++;
		if (val.size >= 1024)
		{
			val = _print_buffer(buffer, val);
		}
	}
	return (val);
}
/**
 * _strcpy - copies and returns a string; triggers print when buffer is full
 * @buffer: destination string, output
 * @src: string to be copied
 * @val: size of current buffer
 * Return: dest
 */
sl_t _strcpy(char *buffer, char *src, sl_t val)
{
	int n;

	n = 0;

	while (src[n] != '\0')
	{
		buffer[val.size] = src[n];
		n++;
		val.size++;
		val.len++;
		if (val.size >= 1024)
		{
			val = _print_buffer(buffer, val);
		}
	}
	return (val);
}

/**
 * _print_buffer - print out entire buffer
 * @buffer: destination string, output
 * @val: size of current buffer
 * Return: size
 */
sl_t _print_buffer(char *buffer, sl_t val)
{
	int i;

	write(1, buffer, val.size);
	for (i = 0; i < 1024; i++)
		buffer[i] = '\0';
	val.size = 0;
	return (val);
}
