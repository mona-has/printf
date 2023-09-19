#include "main.h"

/**
* g_specifier - entry point
*
* @x: string
*
* Return: number of bytes printed
*/

int (*g_specifier(char *x))(va_list ptr, para_s *para)
{
	specif_s specifiers[] = {
	{"c", pr_char},
	{"d", pr_int},
	{"i", pr_int},
	{"s", pr_string},
	{"%", pr_percent},
	{"b", pr_binary},
	{"o", pr_octal},
	{"u", pr_unsign},
	{"x", pr_x},
	{"X", pr_X},
	{"p", pr_addres},
	{"S", pr_S},
	{"r", pr_rev},
	{"R", pr_rot13},
	{NULL, NULL}
	};
	int a = 0;

	while (specifiers[a].specifiers)
	{
		if (*x == specifiers[a].specifiers[0])
		{
			return (specifiers[a].f);
		}
		a++;
	}
	return (NULL);
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
