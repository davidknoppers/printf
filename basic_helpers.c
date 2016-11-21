#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * rev_string - reverse string
 * @s: beginning of string
 * Return: s
 */
char *rev_string(char *s)
{
	char temp;
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (j <= i / 2)
	{
		temp = s[j];
		s[j] = s[i - j];
		s[i - j] = temp;
		j++;
	}
	return (s);
}

/**
 * _puts - print string
 * @str: string beginning
 * Return: nothing
 */
void _puts(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
}
