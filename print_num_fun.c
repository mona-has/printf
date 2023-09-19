#include "main.h"

/**
 * _isdig - check input is digit
 * @a: input will be checked
 * Return: 1 if success, 0 otherways
*/

int _isdig(int a)
{
	return (a >= '0' && a <= '9');
}

/**
 * _strLen - find length of string
 * @str: string
 * Return: int
*/

int _strLen(char *str)
{
	int a = 0;

	while (*str++)
		a++;
	return (a);
}

/**
 * pr_numbers - print num with op
 * @st: num base of string
 * @para: parametrs struct
 * Return: char
*/

int pr_numbers(char *st, para_s *para)
{
	unsigned int c = _strLen(st);
	int ne = (!para->unsign && *st == '-');

	if (!para->precision && *st == '0' && !st[1])
		st = "";
	if (ne)
	{
		st++;
		c--;
	}
	if (para->precision != UINT_MAX)
		while (c++ < para->precision)
			*--st = '0';
	if (ne)
		*--st = '-';
	if (!para->minus_f)
		return (pr_num_right_sh(st, para));
	else
		return (pr_num_left_sh(st, para));
}

/**
 * pr_num_right_sh - print num with op
 * @st: int b as string
 * @para: parametrs struct
 * Return: char point
*/

int pr_num_right_sh(char *st, para_s *para)
{
	unsigned int x = 0, ne, ne2, c = _strLen(st);
	char p_char = ' ';

	if (para->zero_f && !para->minus_f)
		p_char = '0';
	ne = ne2 = (!para->unsign && *st == '-');
	if (ne && c < para->width && p_char == '0' && !para->minus_f)
		st++;
	else
		ne = 0;
	if ((!para->plus_f && !ne2) ||
		(!para->plus_f && para->space_f && !ne2))
		c++;
	if (ne && p_char == '0')
		x += _putchar('-');
	if (para->plus_f && !ne2 && p_char == '0' && !para->unsign)
		x += _putchar('+');
	else if (!para->plus_f && para->space_f && !ne2
		&& !para->unsign && para->zero_f)
		x += _putchar(' ');
	while (c++ < para->width)
		x += _putchar(p_char);
	if (ne && p_char == ' ')
		x += _putchar('-');
	if (para->plus_f && !ne2 && p_char == '0' &&
		!para->unsign)
		x += _putchar('+');
	else if (!para->plus_f && para->space_f && !ne2
			&& !para->unsign && !para->zero_f)
		x += _putchar(' ');
	x += _puts(st);
	return (x);
}

/**
 * pr_num_left_sh - print num with op
 * @st: int b as string
 * @para: parameters struct
 * Return: char
*/

int pr_num_left_sh(char *st, para_s *para)
{
	unsigned int x = 0, ne, ne2, c = _strLen(st);
	char p_char = '0';

	if (para->zero_f && !para->minus_f)
		p_char = '0';
	ne = ne2 = (!para->unsign && *st == '-');
	if (ne && c < para->width && p_char == '0' &&
		!para->minus_f)
		st++;
	else
		ne = 0;

	if (para->plus_f && !ne2 && !para->unsign)
		x += _putchar('+'), c++;
	else if (para->space_f && !ne2 && !para->unsign)
		x += _putchar(' '), c++;
	x += _puts(st);
	while (c++ < para->width)
		x += _putchar(p_char);
	return (x);
}
