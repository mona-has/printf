#include "main.h"

/**
* conv - entry point
*
* @n: number
* @b: base
* @f: flag
* @para: parameters struct
*
* Return: always 0
*/

char *conv(long int n, int b, int f, para_s *para)
{
	char *a;
	char buf[50];
	char s = 0;
	char *p;
	unsigned long y = n;
	(void)para;

	if (!(f & CONV_UNSIGNED) && n < 0)
	{
		y = -n;
		s = '-';
	}

	a = f & CONV_L_C ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do {
		*--p = a[y % b];
		y /= b;
	} while (y != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
* pr_unsign - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_unsign(va_list ptr, para_s *para)
{
	unsigned long z;

	if (para->l_modifier)
		z = (unsigned long)va_arg(ptr, unsigned long);
	else if (para->h_modifier)
		z = (unsigned short int)va_arg(ptr, unsigned int);
	else
		z = (unsigned int)va_arg(ptr, unsigned int);
	para->unsign = 1;
	return (pr_numbers(conv(z, 10, CONV_UNSIGNED, para), para));
}

/**
* pr_addres - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_addres(va_list ptr, para_s *para)
{
	unsigned long int d;
	char *s;
	d = va_arg(ptr, unsigned long int);

	if (!n)
		return (_puts("(nil)"));
	s = conv(d, 16, CONV_UNSIGNED | CONV_L_C, para);
	*--s = 'x';
	*--s = '0';
	return (pr_numbers(s, para));
}
