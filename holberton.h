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
int _print_buffer (char *buffer, int size);

/* LE PRINTF */
int _printf(const char *format, ...);

/* printchar function */
int _printchar(va_list c, char *buffer, int size);

/* printstring function */
int _printstring(va_list c, char *buffer, int size);

/* printnum function */
int _printnum(va_list c, char *buffer, int size);

/* printunsign function */
int _printunsign(va_list c, char *buffer, int size);

/* printoct function */
int _printoct(va_list c);

/* printhex function */
int _printhex(va_list c);

/* print upper case hex function */
int _printhexUP(va_list c);

/* print binary */
int _printbinary(va_list c);

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
	int dec;
	char hex;
} hex_t;
#endif
