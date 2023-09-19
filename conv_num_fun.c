#include "main.h"

/**
 * pr_x - print a hex num in LC
 * @ptr: pointer
 * @para: parametrs struct
 * Return: pointed byte
*/

int pr_x(va_list ptr, para_s *para)
{
	unsigned long a;
	int b = 0;
	char *st;

	if (para->l_modifier)
		a = (unsigned long)va_arg(ptr, unsigned long);
	else if (para->h_modifier)
		a = (unsigned short int)va_arg(ptr, unsigned int);
	else
		a = (unsigned int)va_arg(ptr, unsigned int);
	st = conv(a, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hashtag_f && a)
	{
		*--st = 'x';
		*--st = '0';
	}
	para->unsign = 1;
	return (b += pr_numbers(st, para));
}

/**
 * pr_X - print hex num in upper-Case
 * @ptr: pointer
 * @para: parameters struct
 * Return: pointed byte
*/

int pr_X(va_list ptr, para_s *para)
{
	unsigned long a;
	int b = 0;
	char *st;

	if (para->l_modifier)
		a = (unsigned long)va_arg(ptr, unsigned long);
	else if (para->h_modifier)
		a = (unsigned short int)va_arg(ptr, unsigned int);
	else
		a = (unsigned int)va_arg(ptr, unsigned int);
	st = conv(a, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag_f && a)
	{
		*--st = 'X';
		*--st = '0';
	}
	para->unsign = 1;
	return (b += pr_numbers(st, para));
}

/**
 * pr_binary - print unsigned binary num
 * @ptr: pointer
 * @para: parameters struct
 * Return: pointed byte
*/

int pr_binary(va_list ptr, para_s *para)
{
	unsigned int x = va_arg(ptr, unsigned int);
	char *st = conv(x, 2, CONVERT_UNSIGNED, para);
	int a = 0;

	if (para->hashtag_f && x)
		*--st = '0';
	para->unsign = 1;
	return (a += pr_numbers(st, para));
}

/**
 * pr_octal - print unsigned octal num
 * @ptr: pointer
 * @para: parameter struct
 * Return: pointed byte
*/

int pr_octal(va_list ptr, para_s *para)
{

	unsigned long a;
	int b = 0;
	char *st;

	if (para->l_modifier)
		a = (unsigned long)va_arg(ptr, unsigned long);
	else if (para->h_modifier)
		a = (unsigned short int)va_arg(ptr, unsigned int);
	else
		a = (unsigned int)va_arg(ptr, unsigned int);
	st = conv(a, 8, CONVERT_UNSIGNED, para);
	if (para->hashtag_f && a)
		*--st = '0';
	para->unsign = 1;
	return (b += pr_numbers(st, para));
}
