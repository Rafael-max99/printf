#include "libftprintf.h"

int	ft_typevoid(t_format *format)
{
	size_t	ptr;

	ptr = (size_t)(*format).type.ptr;
	/* NULL pointer should print (nil) on many systems */
	if (ptr == 0)
	{
		(*format).ints.len = 5; /* length of "(nil)" */
		if ((*format).flags.minus)
		{
			ft_putstr("(nil)");
			(*format).logic.printed += (*format).ints.len;
			(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
		}
		else
		{
			(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
			ft_putstr("(nil)");
			(*format).logic.printed += (*format).ints.len;
		}
		return ((*format).logic.printed);
	}

	(*format).type.str = ft_hexa(ptr);
	(*format).ints.len = ft_strlen((*format).type.str) + 2;
	if ((*format).flags.minus)
	{
		ft_putstr("0x");
		ft_putstr((*format).type.str);
		(*format).logic.printed += (*format).ints.len;
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
		ft_putstr("0x");
		ft_putstr((*format).type.str);
		(*format).logic.printed += (*format).ints.len;
	}
	free((*format).type.str);
	return ((*format).logic.printed);
}
