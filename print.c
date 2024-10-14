/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:23:36 by makurek           #+#    #+#             */
/*   Updated: 2024/10/14 18:32:07 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	show_with_buffer(unsigned long n, const char *base)
{
	char	buffer[65];
	int		i;
	int		base_len;

	base_len = ft_strlen(base);
	i = 64;
	buffer[i] = '\0';
	if (n == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	while (n > 0)
	{
		buffer[i--] = base[n % base_len];
		n /= base_len;
	}
	ft_putstr(&buffer[i + 1]);
	return (63 - i);
}

static int	handle_signed(long n)
{
	if (n == LONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		return (20);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	return (0);
}

int	print_int(unsigned long n, const char *base, int is_signed)
{
	int	negative;

	negative = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (is_signed)
	{
		negative = handle_signed((long)n);
		if (negative == 11)
			return (11);
		else if (negative)
			n = -n;
	}
	return (negative + show_with_buffer(n, base));
}

int	print_dec(long n, int is_signed)
{
	return (print_int(n, "0123456789", is_signed));
}

int	print_hex(unsigned long n, int uppercase)
{
	char	*base;

	base = "0123456789abcdef";
	if (uppercase)
		base = "0123456789ABCDEF";
	return (print_int(n, base, 0));
}
