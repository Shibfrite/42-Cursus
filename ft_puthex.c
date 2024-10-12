#include "libft.h"

void	ft_puthex(unsigned int n, int uppercase)
{
	char *hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n / 16)
		ft_puthex(n / 16, uppercase);
	ft_putchar(hex_digits[n % 16]);
}
