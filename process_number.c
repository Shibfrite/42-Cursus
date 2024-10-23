/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:34:49 by makurek           #+#    #+#             */
/*   Updated: 2024/10/23 21:25:05 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	convert_number(char *buffer, unsigned long n, const char *base, int *i)
{
	int	base_len;

	base_len = ft_strlen(base);
	while (n && *i)
	{
		buffer[--(*i)] = base[n % base_len];
		n /= base_len;
	}
}

static int	init_and_convert(char *buffer, long n,
				const char *base, t_format *fmt)
{
	unsigned long	un;
	int				i;

	ft_memset(buffer, 0, BUFFER_SIZE);
	un = n;
	if (n < 0 && ft_strchr("di", fmt->specifier))
		un = -n;
	i = BUFFER_SIZE - 1;
	buffer[i] = '\0';
	if (fmt->minus)
		while (fmt->width-- && i)
			buffer[--i] = ' ';
	if (un == 0 && fmt->precision != 0)
		buffer[--i] = '0';
	else
		convert_number(buffer, un, base, &i);
	while (fmt->precision > BUFFER_SIZE - 1 - i && i)
		buffer[--i] = '0';
	return (i);
}

static void	apply_prefix(char *buffer, unsigned long n, t_format *fmt, int *i)
{
	if (ft_strchr("di", fmt->specifier))
	{
		if (fmt->negative)
			buffer[--(*i)] = '-';
		else if (fmt->plus)
			buffer[--(*i)] = '+';
		else if (fmt->space)
			buffer[--(*i)] = ' ';
	}
	else if ((fmt->hash && ft_strchr("xX", fmt->specifier) && n != 0)
		|| fmt->specifier == 'p')
	{
		if (fmt->specifier == 'X')
			buffer[--(*i)] = 'X';
		else
			buffer[--(*i)] = 'x';
		buffer[--(*i)] = '0';
	}
}

static void	apply_flags(char *buffer, unsigned long n, t_format *fmt, int *i)
{
	char	pad;

	if (fmt->zero)
		pad = '0' ;
	else
		pad = ' ';
	if (!fmt->minus)
		while (fmt->width-- && *i)
			buffer[--(*i)] = pad;
	apply_prefix(buffer, n, fmt, i);
}

int	process_number(unsigned long n, const char *base, t_format *fmt)
{
	char	buffer[BUFFER_SIZE];
	int		i;

	if (fmt->specifier == 'p' && n == 0)
		return (write(1, "(nil)", 5));
	i = init_and_convert(buffer, n, base, fmt);
	apply_flags(buffer, n, fmt, &i);
	return (write(1, &buffer[i], BUFFER_SIZE - 1 - i));
}
