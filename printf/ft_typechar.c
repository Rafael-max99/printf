#include "libftprintf.h"

int	ft_typechar(t_flags flag, char value, int width)
{
	int	printed;

	printed = 1;
	if (flag.minus)
	{
		ft_putchar(value);
		printed += ft_padding(width, 1, ' ');
	}
	else
	{
		printed += ft_padding(width, 1, ' ');
		ft_putchar(value);
	}
	return (printed);
}
