#include "main.h"

/**
* g_specifier - entry point
*
* @x: string
* @ptr: pointer
* @para: parameters struct
*
* Return: number of bytes printed
*/

int g_specifier(char *x, va_list ptr, para_s *para)
{
	switch (*x)
	{
		case 'c':
			return (pr_char(ptr, para));
		case 'd':
		case 'i':
			return (pr_int(ptr, para));
		case 's':
			return (pr_string(ptr, para));
		case '%':
			return (pr_percent(ptr, para));
		case 'b':
			return (pr_binary(ptr, para));
		case 'o':
			return (pr_octal(ptr, para));
		case 'u':
			return (pr_unsign(ptr, para));
		case 'x':
			return (pr_x(ptr, para));
		case 'X':
			return (pr_X(ptr, para));
		case 'p':
			return (pr_addres(ptr, para));
		case 'S':
			return (pr_S(ptr, para));
		case 'r':
			return (pr_rev(ptr, para));
		case 'R':
			return (pr_rot13(ptr, para));
		default:
			return (-1);
	}
}


/**
* g_printfun - entry point
*
* @x: string
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/
int g_printfun(char *x, va_list ptr, para_s *para)
{
	int (*f)(va_list, para_s *) = g_specifier(x);

	if (f)
		return (f(ptr, para));
	return (0);
}

/**
* g_flag - entry point
*
* @x: string
* @para: the parameters struct
*
* Return: always 0
*/

int g_flag(char *x, para_s *para)
{
	int a = 0;

	switch (*x)
	{
		case '+':
			a = para->plus_f = 1;
			break;
		case ' ':
			a = para->space_f = 1;
			break;
		case '#':
			a = para->hashtag_f = 1;
			break;
		case '-':
			a = para->minus_f = 1;
			break;
		case '0':
			a = para->zero_f = 1;
			break;
	}
	return (a);
}

/**
* g_modifier - entry point
*
* @x: input string
* @para: parameters struct
*
* Return: always 0
*/

int g_modifier(char *x, para_s *para)
{
	int a = 0;

	switch (*x)
	{
		case 'h':
			a = para->h_modifier = 1;
			break;
		case 'l':
			a = para->l_modifier = 1;
			break;
	}
	return (a);
}

/**
* g_width - entry point
*
* @x: string
* @para: parameters struct
* @ptr: pointer
*
* Return: always 0
*/

char *g_width(char *x, para_s *para, va_list ptr)
{
	int i = 0;

	if (*x == '*')
	{
		i = va_arg(ptr, int);
		x++;
	}
	else
	{
		while (_isdig(*x))
			i = i * 10 + (*x++ - '0');
	}
	para->width = i;
	return (x);
}
