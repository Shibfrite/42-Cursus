/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:56:51 by makurek           #+#    #+#             */
/*   Updated: 2024/10/14 19:04:36 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format_specifier(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'd' || *format == 'i')
		count += print_dec(va_arg(args, int), 1);
	else if (*format == 's')
		count += print_str(va_arg(args, char *));
	else if (*format == 'p')
		count += print_addr(va_arg(args, void *));
	else if (*format == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (*format == 'u')
		count += print_dec(va_arg(args, unsigned int), 0);
	else if (*format == 'c')
		count += print_char((char)va_arg(args, int));
	else if (*format == '%')
		count += print_char('%');
	return (count);
}

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
			count += handle_format_specifier(format, args);
		}
		else
			count += print_char(*format);
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
