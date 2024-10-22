/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_width_calc.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/21 15:41:32 by makurek		   #+#	#+#			 */
/*   Updated: 2024/10/22 18:37:14 by makurek          ###   ########.fr       */
/*																		*/
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_padding(t_format *fmt, va_list args)
{
	va_list copy_args;
    int content_len;
    int n_signed;
    unsigned int n_unsigned;
    unsigned long n_unsigned_ptr;

    va_copy(copy_args, args);
    content_len = 0;

    if (ft_strchr("di", fmt->specifier))
    {
        n_signed = va_arg(copy_args, int); 
		if (n_signed < 0)
		{
			fmt->negative = 1;
			n_signed = -n_signed;
		}
		content_len = ft_numlen(n_signed, 10);
    }
    else if (ft_strchr("uxX", fmt->specifier))
    {
        n_unsigned = va_arg(copy_args, unsigned int);
        if (fmt->specifier == 'x' || fmt->specifier == 'X')
            content_len = ft_numlen(n_unsigned, 16);
        else
            content_len = ft_numlen(n_unsigned, 10);
    }
	else if (fmt->specifier == 'p')
    {
        n_unsigned_ptr = va_arg(copy_args, unsigned long);
        content_len = ft_numlen(n_unsigned_ptr, 16) + 2;
    }
	else
		content_len = 1;
	if (fmt->precision > content_len && fmt->specifier != 's')
		content_len = fmt->precision;
	if (fmt->precision < content_len && fmt->specifier == 's'
		&& fmt->precision != -1)
		content_len = fmt->precision;
	if (fmt->negative || fmt->plus || fmt->space)
		fmt->width--;
	if ((fmt->hash && ft_strchr("xX", fmt->specifier)))
		fmt->width -= 2;
	if (fmt->width > content_len)
		fmt->width -= content_len;
	else
		fmt->width = 0;
	va_end(copy_args);
}
