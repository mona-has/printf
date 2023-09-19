#include "main.h"

/**
 * pr_from_to - print a range of char adress
 * @from: start point
 * @to: end point
 * @expec: expect addres
 * Return: byte printed
*/

int pr_from_to(char *from, char *to, char *expec)
{
	int s = 0;

	while (from <= to)
	{
		if (from != expec)
			s += _putchar(*from);
		from++;
	}
	return (s);
}

/**
 * pr_rev - print string in revers
 * @ptr: pointer
 * @para: parameters struct
 * Return: printed byte
*/

int pr_rev(va_list ptr, para_s *para)
{
	int le, s = 0;
	char *st = va_arg(ptr, char *);
	(void)para;

	if (st)
	{
		for (le = 0; *st; st++)
			le++;
		st--;
		for (; le > 0; le--, st--)
			s += _putchar(*st);
	}
	return (s);
}

/**
 * pr_rot13 -print string in rot13
 * @ptr: pointer string
 * @para: parameters struct
 * Return: printed byte
*/

int pr_rot13(va_list ptr, para_s *para)
{
	int s, in;
	int co = 0;
	char ar[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLM  nopqrstuvwxyzabcdefghijklm";
	char *x = va_arg(ptr, char *);
	(void) para;

	s = 0;
	in = 0;
	while (x[s])
	{
		if ((x[s] >= 'A' && x[s] <= 'Z')
			|| (x[s] >= 'a' && x[s] <= 'z'))
		{
			in = x[s] - 65;
			co += _putchar(ar[in]);
		}
		else
			co += _putchar(x[s]);
		s++;
	}
	return (co);
}

