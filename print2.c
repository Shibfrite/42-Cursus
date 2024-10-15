/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:32:18 by makurek           #+#    #+#             */
/*   Updated: 2024/10/15 15:04:02 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(const char *str)
{
	if (str == NULL)
			return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_addr(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	count = print_str("0x");
	if (!addr)
		return (count + print_char('0'));
	return (count + print_hex(addr, 0));
}
