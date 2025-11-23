#include "libftprintf.h"

int	ft_typevoid(t_flags flag, void *value, int width)
{
	int	len;
	size_t	ptr;
	char	*str;
	int	printed;

	ptr = (size_t)value;
	str = ft_hexa(ptr);
	len = ft_strlen(str) + 2;
	printed = 0;
	if (flag.minus)
	{
		ft_putstr("0x");
		ft_putstr(str);
		printed += len;
		printed += ft_padding(width, len, ' ');
	}
	else
	{
		printed += ft_padding(width, len, ' ');
		ft_putstr("0x");
		ft_putstr(str);
		printed += len;
	}
	free(str);
	return (printed);
}
