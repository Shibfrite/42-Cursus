/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_width_calc.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/21 15:41:32 by makurek		   #+#	#+#			 */
/*   Updated: 2024/10/21 18:46:03 by makurek          ###   ########.fr       */
/*																		*/
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_padding(t_format *fmt, va_list args)
{
	va_list			copy_args;
	int				content_len;
	unsigned long	n;
	char			*str;

	va_copy(copy_args, args);
	content_len = 0;
	if (ft_strchr("diuxX", fmt->specifier))
	{
		n = va_arg(copy_args, unsigned long);
		if (fmt->specifier == 'x' || fmt->specifier == 'X')
			content_len = ft_numlen(n, 16);
		else
			content_len = ft_numlen(n, 10);
	}
	else if (fmt->specifier == 's')
	{
		str = va_arg(copy_args, char *);
		if (str)
			content_len = ft_strlen(str);
		else
			content_len = 6;
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
	if ((fmt->hash && ft_strchr("xX", fmt->specifier)) || fmt->specifier == 'p')
		fmt->width -= 2;
	if (fmt->width > content_len)
		fmt->width -= content_len;
	else
		fmt->width = 0;
	va_end(copy_args);
}
