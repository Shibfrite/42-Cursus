/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/18 17:51:27 by makurek		   #+#	#+#			 */
/*   Updated: 2024/10/21 18:36:06 by makurek          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

static void
	convert_number(char *buffer, unsigned long n, const char *base, int *i)
{
	int	base_len;

	base_len = ft_strlen(base);
	while (n > 0 && *i > 0)
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
	{
		un = -n;
		fmt->negative = 1;
	}
	i = BUFFER_SIZE - 1;
	buffer[i] = '\0';
	if (un == 0 && fmt->precision != 0)
		buffer[--i] = '0';
	else
		convert_number(buffer, un, base, &i);
	while (fmt->precision > BUFFER_SIZE - 1 - i && i > 0)
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

	apply_prefix(buffer, n, fmt, i);
	if (fmt->zero)
		pad = '0' ;
	else
		pad = ' ';
	while (fmt->width > 0 && *i > 0 && !fmt->minus)
	{
		buffer[--(*i)] = pad;
		fmt->width--;
	}
}

int	process_number(unsigned long n, const char *base, t_format *fmt)
{
	char	buffer[BUFFER_SIZE];
	int		i;
	int		len;

	if (fmt->specifier == 'p' && n == 0)
		return (write(1, "(nil)", 5));
	i = init_and_convert(buffer, n, base, fmt);
	apply_flags(buffer, n, fmt, &i);
	len = BUFFER_SIZE - 1 - i;
	if (fmt->minus)
	{
		write(1, &buffer[i], len);
		while (fmt->width > 0)
		{
			write(1, " ", 1);
			fmt->width--;
			len++;
		}
	}
	else
		write(1, &buffer[i], len);
	return (len);
}
