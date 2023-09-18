#include "main.h"

/**
* init_para - entry point
*
* @para: parameters struct
* @ptr: pointer
*
* Return: void
*/

void init_para(para_s *para, va_list ptr)
{
	(void)ptr;

	para->unsign = 0;
	para->plus_f = 0;
	para->space_f = 0;
	para->hashtag_f = 0;
	para->zero_f = 0;
	para->minus_f = 0;
	para->width_f = 0;
	para->precision_f = UINT_MAX;
	para->h_modifier = 0;
	para->l_modifier = 0;
}

