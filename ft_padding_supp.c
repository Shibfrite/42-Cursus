/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_padding_supp.c                                  :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/21 15:41:32 by makurek		   #+#	#+#			 */
/*   Updated: 2024/10/29 18:52:13 by makurek          ###   ########.fr       */
/*																		*/
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_signed_number(t_format *fmt, va_list args)
{
	int	n_signed;

	n_signed = va_arg(args, int);
	if (!fmt->precision && !n_signed)
		return (0);
	if (n_signed < 0)
	{
		fmt->negative = 1;
		n_signed = -n_signed;
	}
	return (ft_numlen(n_signed, 10));
}

int	handle_unsigned_number(t_format *fmt, va_list args)
{
	unsigned int	n_unsigned;

	n_unsigned = va_arg(args, unsigned int);
	if (!fmt->precision && !n_unsigned)
		return (0);
	if (fmt->specifier == 'x' || fmt->specifier == 'X')
		return (ft_numlen(n_unsigned, 16));
	else
		return (ft_numlen(n_unsigned, 10));
}

int	handle_pointer(va_list args)
{
	unsigned long	n_unsigned_ptr;

	n_unsigned_ptr = va_arg(args, unsigned long);
	if (!n_unsigned_ptr)
		return (ft_strlen("(nil)"));
	return (ft_numlen(n_unsigned_ptr, 16) + 2);
}

int	handle_string(va_list args, int precision)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		if (precision == -1 || precision >= 6)
			str = "(null)";
		else
			str = "";
	}
	return (ft_strlen(str));
}
