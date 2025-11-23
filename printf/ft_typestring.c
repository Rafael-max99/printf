#include "libftprintf.h"

int	ft_typestring(t_flags flag, char *value, int width, int precision)
{
	int	len;
	int	printed;

	printed = 0;
	if (!value)
		value = "(null)";
	len = ft_strlen(value);
	if (flag.point && precision < len)
		len = precision;
	if (flag.minus)
	{
		write (1, value, len);
		printed += len;
		printed += ft_padding(width, len, ' ');
	}
	else
	{
		printed += ft_padding(width, len, ' ');
		write (1, value, len);
		printed += len;
	}
	return (printed);
}
