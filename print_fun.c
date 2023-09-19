#include "main.h"

/**
* pr_char - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_char(va_list ptr, para_s *para)
{
	char dab_char = ' ';
	unsigned int dab = 1, s = 0, ca = va_arg(ptr, int);

	if (para->minus_f)
		s += _putchar(ca);
	while (dab++ < para->width)
		s += _putchar(dab_char);
	if (!para->minus_f)
		s += _putchar(ca);
	return (s);
}


/**
* pr_int - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_int(va_list ptr, para_s *para)
{
	long z;

	if (para->l_modifier)
		z = va_arg(ptr, long);
	else if (para->h_modifier)
		z = (short int)va_arg(ptr, int);
	else
		z = (int)va_arg(ptr, int);
	return (pr_numbers(conv(z, 10, 0, para), para));
}


/**
* pr_percent - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_percent(va_list ptr, para_s *para)
{
	(void)ptr;
	(void)para;

	return (_putchar('%'));
}

/**
* pr_string - entry point
*
* @ptr: pointer
* @para: parameters struct
*
* Return: always 0
*/

int pr_string(va_list ptr, para_s *para)
{
	char *s = va_arg(ptr, char *);
	char dab_char = ' ';
	unsigned int dab = 0, m = 0, a, k;

	(void)para;
	switch ((int)(!s))
		case 1:
			s = NULL_STRING;

	k = dab = _strLen(s);
	if (para->precision < dab)
		k = dab = para->precision;

	if (para->minus_f)
	{
		if (para->precision != UINT_MAX)
			for (a = 0, a < dab, a++)
				m += _putchar(*s++);
		else
			m += _puts(s);
	}

	while (k++ < para->width)
		m += _putchar(dab_char);
	if (!para->minus_f)
	{
		if (para->precision != UINT_MAX)
			for (a = 0, a < dab, a++)
				m += _putchar(*s++);
		else
			m += _puts(s);
	}
	return (m);
}

/**
* pr_S - entry point
*
* @ptr: pointer
* @para: parameters
*
* Return: always 0
*/

int pr_S(va_list ptr, para_s *para)
{
	char *s = va_arg(ptr, char *);
	char *h;
	int m = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			m += _putchar('\\');
			m += _putchar('x');
			h = conv(*s, 16, 0, para);
			if (!h[1])
				m += _putchar('0');
			m += _puts(h);
		}
		else
		{
			m += _putchar(*s);
		}
	}
	return (m);
}
