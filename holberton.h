#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

/* basic putchar function */
int _putchar(char c);

/* reverse string */
char *rev_string(char *s);

/* print string */
void _puts(char *str);

/* string copy */
int _strcpy(char *buffer, char *src, int size);

/* print buffer */
int _print_buffer(char *buffer, int size);

/* LE PRINTF */
int _printf(const char *format, ...);

/* printchar function */
int _char(va_list c, char *buffer, int size);

/* printstring function */
int _str(va_list c, char *buffer, int size);

/* printnum function */
int _num(va_list c, char *buffer, int size);

/* printunsign function */
int _unsign(va_list c, char *buffer, int size);

/* printoct function */
int _oct(va_list c, char *buffer, int size);

/* printhex function */
int _hex(va_list c);

/* print upper case hex function */
int _hexUP(va_list c);

/* print binary */
int _bi(va_list c);

/* printpercent */
int _percent(va_list c, char *buffer, int size);

/**
 * struct functions - structure to find corresponding functions
 * @format_str: format string to compare to
 * @f: function pointer
 */
typedef struct functions
{
	char *format_str;
	int (*f)();
} print_t;

/**
 * struct hexchart - conversion between num and hex;
 * @dec: int value
 * @hex: char value
 */
typedef struct hexchart
{
	unsigned int dec;
	char hex;
} hex_t;
#endif
