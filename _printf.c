#include "main.h"

/**
 * _printf - function to print evrything
 * @format: format of string
 * Return: num of byte will be print
*/

int _printf(const char *format, ...)
{
	int num = 0;
	va_list ptr;
	char *b, *start;
	para_s para = PARA_INIT;

	va_start(ptr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_para(&para, ptr);
		if (*b != '%')
		{
			num += _putchar(*b);
			continue;
		}
		start = b;
		b++;
		while (g_flag(b, &para))
		{
			b++;
		}
		b = g_width(b, &para, ptr);
		b = g_precision(b, &para, ptr);
		if (g_modifier(b, &para))
			b++;
		if (!g_specifier(b))
			num += pr_from_to(start, b,
			para.l_modifier || para.h_modifier ? b - 1 : 0);
		else
			num += g_printfun(b, ptr, &para);
	}
	_putchar(BUF_FLUSH);
	va_end(ptr);
	return (num);
}
