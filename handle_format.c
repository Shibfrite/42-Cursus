/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:23:36 by makurek           #+#    #+#             */
/*   Updated: 2024/10/21 16:30:17 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static const char	*get_base(char specifier)
{
	if (ft_strchr("xp", specifier))
		return ("0123456789abcdef");
	if (specifier == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789");
}

static unsigned long	get_arg_value(va_list args, char specifier)
{
	if (ft_strchr("di", specifier))
		return ((long)va_arg(args, int));
	if (specifier == 'p')
		return ((unsigned long)va_arg(args, void *));
	return (va_arg(args, unsigned int));
}

int	process_format(t_format *fmt, va_list args)
{
	const char	*base;
	const char	*str;
	char		c;

	if (ft_strchr("dixXup", fmt->specifier))
	{
		base = get_base(fmt->specifier);
		return (process_number(get_arg_value(args, fmt->specifier), base, fmt));
	}
	else if (fmt->specifier == 's')
	{
		str = va_arg(args, const char *);
		if (str == NULL)
			str = "(null)";
		return (process_string(str, fmt));
	}
	else if (fmt->specifier == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (fmt->specifier == '%')
		return (write(1, "%", 1));
	return (0);
}
