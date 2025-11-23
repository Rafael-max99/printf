#include "libftprintf.h"

int	ft_padding(int width, int n, char c)
{
	int	printed;

	printed = 0;
	while (width-- > n)
	{
		ft_putchar(c);
		printed++;
	}
	return (printed);
}
