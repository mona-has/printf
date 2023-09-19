#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTBUT_B_S 1024
#define BUF_FLUSH -1

#define NULL_STRING "(NULL)"

#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_L_C 1
#define CONV_UNSIGNED 2

/**
 * struct paramet - struct of parameter
 * @unsign: if unsigned val ,flags
 * @plus_f: on when plus_f if found
 * @space_f: on when space_f if found
 * @hashtag_f: on when hashtagg_f if found
 * @zero_f: on when zero_f if found
 * @minus_f: on when minus_f if found
 * @width_f: on when width_f if found
 * @precision_f: on when precision_f if found
 * @h_modifier: on when h_modifier if found
 * @l_modifier: on when l_modifier if found
*/

typedef struct paramet
{
	unsigned int unsign : 1;
	unsigned int plus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int minus_f : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} para_s;

/**
 * struct specifiers - token
 * @specifiers: token format
 * @f: function
*/

typedef struct specifiers
{
	char *specifiers;
	int (*f)(va_list, para_s *);
} specif_s;

/* put_fun file */
int _puts(char *st);
int _putchar(int s);

/* print_fun file */
int pr_char(va_list ptr, para_s *para);
int pr_int(va_list ptr, para_s *para);
int pr_percent(va_list ptr, para_s *para);
int pr_string(va_list ptr, para_s *para);
int pr_S(va_list ptr, para_s *para);

/* number_fun file */
char *conv(long int n, int b, int f, para_s *para);
int pr_unsign(va_list ptr, para_s *para);
int pr_addres(va_list ptr, para_s *para);

/* specfiers_fun file */
int g_specifier(char *x, va_list ptr, para_s *para);
int g_printfun(char *x, va_list ptr, para_s *para);
int g_flag(char *x, para_s *para);
int g_modifier(char *x, para_s *para);
char *g_width(char *x, para_s *para, va_list ptr);

/* conv_num_fun file */
int pr_x(va_list ptr, para_s *para);
int pr_X(va_list ptr, para_s *para);
int pr_binary(va_list ptr, para_s *para);
int pr_octal(va_list ptr, para_s *para);

/* simple_pr_fun file*/
int pr_from_to(char *from, char *to, char *expec);
int pr_rev(va_list ptr, para_s *para);
int pr_rot13(va_list ptr, para_s *para);

/* print_num_fun file */
int _isdig(int a);
int _strLen(char *str);
int pr_numbers(char *st, para_s *para);
int pr_num_left_sh(char *st, para_s *para);
int pr_num_right_sh(char *st, para_s *para);

/* para_fun file */
void init_para(para_s *para, va_list ptr);

/* string_filed_fun file */
char *g_precision(char *q, para_s *para, va_list ptr);

/* _printf_fun file */
int _printf(const char *format, ...);

#endif
