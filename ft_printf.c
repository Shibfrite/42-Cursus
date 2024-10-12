/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:56:51 by makurek           #+#    #+#             */
/*   Updated: 2024/10/12 18:57:35 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				ft_putaddr(va_arg(args, void *));
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned int), 0);
			else if (*format == 'X')
				ft_puthex(va_arg(args, unsigned int), 1);
			else if (*format == 'u')
				ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(*format);
		count++;
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return 0;
}*/
