#include "libft.h"

void ft_putaddr(void *addr)
{
	unsigned long address;

	address = (unsigned long)addr;
	ft_putchar('0');
	ft_putchar('x');
	if (!address)
		ft_putchar('0');
	ft_putbase(address, "0123456789abcdef");
}
