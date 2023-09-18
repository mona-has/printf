#include "main.h"

/**
 * g_precision - get precision from format
 * @q: format string
 * @para: paramet struct
 * @ptr: arg pointer
 * Return: pointer
*/

char *g_precision(char *q, para_s *para, va_list ptr)
{
	int a = 0;

	if (*q != '.')
		return (q);
	q++;
	if (*q == '*')
	{
		a = va_arg(ptr, int);
		q++;
	}
	else
	{
		while (_isdig(*q))
			a = a * 10 + (*q++ - '0');
	}
	para->precision = a;
	return (q);
}
