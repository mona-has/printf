#include "main.h"

/**
* _puts - entry point
*
* @st: stdin string
*
* Return: always 0
*/

int _puts(char *st)
{
	char *x = st;

	while (*st)
		_putchar(*st++);
	return (st - x);
}

/**
* _putchar - entry point
*
* @s: input character
*
* Return: on success 1
*	on error -1
*/

int _putchar(int s)
{
	int y = 0;
	char b[OUTBUT_B_S];

	if (s != BUF_FLUSH)
		b[y++] = s;
	if (s == BUF_FLUSH || y >= OUTBUT_B_S)
	{
		write(1, b, y);
	}
	return (1);
}
