#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

/**
 * struct size_len - store size of buffer and total length
 * @size: size in buffer
 * @len: total length
 * @skip: stuff to skip
 */
typedef struct size_len
{
	int size;
	int len;
} sl_t;

/* basic putchar function */
int _putchar(char c);

/* reverse string */
char *rev_string(char *s);

/* print string */
void _puts(char *str);

/* char copy */
sl_t _charcpy(char *buffer, char *src, sl_t val);

/* string copy */
sl_t _strcpy(char *buffer, char *src, sl_t val);

/* print buffer */
sl_t _print_buffer(char *buffer, sl_t val);

/* LE PRINTF */
int _printf(const char *format, ...);

/* printchar function */
sl_t _char(va_list c, char *buffer, sl_t val);

/* printstring function */
sl_t _str(va_list c, char *buffer, sl_t val);

/* printnum function */
sl_t _num(va_list c, char *buffer, sl_t val);

/* printunsign function */
sl_t _unsign(va_list c, char *buffer, sl_t val);

/* printoct function */
sl_t _oct(va_list c, char *buffer, sl_t val);

/* printhex function */
sl_t _hex(va_list c, char *buffer, sl_t val);

/* print upper case hex function */
sl_t _hexUP(va_list c, char *buffer, sl_t val);

/* print binary */
sl_t _bi(va_list c, char *buffer, sl_t val);

/* printpercent */
sl_t _percent(va_list c, char *buffer, sl_t val);

/* percent helper */

/**
 * struct functions - structure to find corresponding functions
 * @format_str: format string to compare to
 * @f: function pointer
 */
typedef struct functions
{
	char *format_str;
	sl_t (*f)();
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
