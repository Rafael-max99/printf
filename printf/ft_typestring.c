
#include "libftprintf.h"

int	ft_typestring(t_format *format)
{
	if (!(*format).type.str)
	{
		/* when string is NULL and precision is specified, print nothing */
		if ((*format).logic.point)
			(*format).ints.len = 0;
		else
			(*format).type.str = "(null)";
	}
	if ((*format).type.str)
		(*format).ints.len = ft_strlen((*format).type.str);
	if ((*format).logic.point && (*format).logic.precision < (*format).ints.len)
		(*format).ints.len = (*format).logic.precision;
	if ((*format).flags.minus)
	{
		write (1, (*format).type.str, (*format).ints.len);
		(*format).logic.printed += (*format).ints.len;
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).ints.len, ' ');
		write (1, (*format).type.str, (*format).ints.len);
		(*format).logic.printed += (*format).ints.len;
	}
	return ((*format).logic.printed);
}
