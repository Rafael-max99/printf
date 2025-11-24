#include "libftprintf.h"

int	ft_typechar(t_format *format)
{
	(*format).logic.printed += 1;
	if ((*format).flags.minus)
	{
		ft_putchar((*format).type.c);
		(*format).logic.printed += ft_padding((*format).logic.width, 1, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width, 1, ' ');
		ft_putchar((*format).type.c);
	}
	return ((*format).logic.printed);
}
