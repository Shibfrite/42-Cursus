/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:55:21 by makurek           #+#    #+#             */
/*   Updated: 2024/10/23 21:25:02 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_content_length(t_format *fmt, va_list copy_args)
{
	int	content_len;

	content_len = 0;
	if (ft_strchr("di", fmt->specifier))
		content_len = handle_signed_number(fmt, copy_args);
	else if (ft_strchr("uxX", fmt->specifier))
		content_len = handle_unsigned_number(fmt, copy_args);
	else if (fmt->specifier == 'p')
		content_len = handle_pointer(copy_args);
	else if (fmt->specifier == 's')
		content_len = handle_string(copy_args);
	else
		content_len = 1;
	return (content_len);
}

static void	adjust_content_length(t_format *fmt, int *content_len)
{
	if (fmt->precision > *content_len && fmt->specifier != 's')
		*content_len = fmt->precision;
	else if (fmt->precision < *content_len
		&& fmt->specifier == 's' && fmt->precision != -1)
		*content_len = fmt->precision;
	if ((fmt->negative || fmt->plus || fmt->space) && fmt->specifier != 's')
		fmt->width--;
	if ((fmt->hash && ft_strchr("xX", fmt->specifier)))
		fmt->width -= 2;
}

void	calculate_padding(t_format *fmt, va_list args)
{
	va_list	copy_args;
	int		content_len;

	va_copy(copy_args, args);
	content_len = get_content_length(fmt, copy_args);
	adjust_content_length(fmt, &content_len);
	if (fmt->width > content_len)
		fmt->width -= content_len;
	else
		fmt->width = 0;
	va_end(copy_args);
}
