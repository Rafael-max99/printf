#include "libftprintf.h"

static int	ft_flagminus(t_format *format)
{
	if ((*format).flags.minus)
	{
		(*format).logic.printed += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).type.nu);
			(*format).logic.printed += (*format).ints.len;
		}
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.total, ' ');
	}
	return ((*format).logic.printed);
}

static int	ft_flagzero(t_format *format)
{
	if ((*format).flags.zero && !(*format).logic.point)
	{
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.total, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).type.nu);
			(*format).logic.printed += (*format).ints.len;
		}
	}
	return ((*format).logic.printed);
}

static int	ft_noflag(t_format *format)
{
	if (!(*format).flags.minus && !((*format).flags.zero && !(*format).logic.point))
	{
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.total, ' ');
		(*format).logic.printed += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).type.nu);
			(*format).logic.printed += (*format).ints.len;
		}
	}
	return ((*format).logic.printed);
}

int	ft_typeunsint(t_format *format)
{

	(*format).ints.len = ft_numlen((*format).type.nu);
	(*format).ints.zeros = 0;
	if ((*format).type.nu == 0 && (*format).logic.point && (*format).logic.precision == 0)
		(*format).ints.len = 0;
	(*format).ints.total = (*format).ints.len;
	if ((*format).logic.point && (*format).logic.precision > (*format).ints.len)
	{
		(*format).ints.zeros = (*format).logic.precision - (*format).ints.len;
		(*format).flags.zero = 0;
		(*format).ints.total = (*format).ints.zeros + (*format).ints.len;
	}
	(*format).logic.printed += ft_flagminus(format);
	(*format).logic.printed += ft_flagzero(format);
	(*format).logic.printed += ft_noflag(format);
	return ((*format).logic.printed);
}
