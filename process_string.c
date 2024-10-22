/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:08:12 by makurek           #+#    #+#             */
/*   Updated: 2024/10/21 16:42:00 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	process_string(const char *str, t_format *fmt)
{
	char	buffer[BUFFER_SIZE];
	int		i;
	int		len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	i = 0;
	if (!fmt->minus)
		while (fmt->width--)
			buffer[i++] = ' ';
	ft_memcpy(&buffer[i], str, len);
	i += len;
	if (fmt->minus)
		while (fmt->width-- > 0)
			buffer[i++] = ' ';
	return (write(1, buffer, i));
}
