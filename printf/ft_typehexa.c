#include "libftprintf.h"

static char	*ft_prefix(char type, char *num_char)
{
	char	*str;


	str = malloc(3);
	if (!str)
		return (NULL);
	str[0] = '0';
	if (type == 'x')
		str[1] = 'x';
	else if (type == 'X')
	{
		str[1] = 'X';
		ft_toupper(num_char);
	}
	str[2] = '\0';
	return (str);
}

static int	ft_flagminus(t_flags flag, t_hexa hexa, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (flag.minus)
	{
		if (flag.hashtag && n != 0)
		{
			ft_putstr(hexa.prefix);
			printed += 2;
		}
		printed += ft_padding(hexa.zeros, 0, '0');
		printed += ft_putstr(hexa.num_char);
		printed += ft_padding(width, hexa.total, ' ');
	}
	return (printed);
}

static int	ft_flagzero(t_flags flag, t_hexa hexa, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (flag.zero && !flag.point)
	{
		if (flag.hashtag && n != 0)
		{
			ft_putstr(hexa.prefix);
			printed += ft_strlen(hexa.prefix);
			hexa.total -= ft_strlen(hexa.prefix);
		}
		printed += ft_padding(width, hexa.total, '0');
		ft_putstr(hexa.num_char);
		printed += ft_strlen(hexa.num_char);
	}
	return (printed);
}

static int	ft_noflag(t_flags flag, t_hexa hexa, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (!flag.minus && !(flag.zero && !flag.point))
	{
		printed += ft_padding(width, hexa.total, ' ');
		if (flag.hashtag && n != 0)
		{
			ft_putstr(hexa.prefix);
			printed += ft_strlen(hexa.prefix);
		}
		printed += ft_padding(hexa.zeros, 0, '0');
		ft_putstr(hexa.num_char);
		printed += ft_strlen(hexa.num_char);
	}
	return (printed);
}

int	ft_typehexa(t_flags flag, unsigned int n, char type, int width, int precision)
{
	t_hexa	hexa;
	int	len;
	int	printed;

	hexa.num_char = ft_hexa(n);
	hexa.prefix = ft_prefix(type, hexa.num_char);
	len = ft_strlen(hexa.num_char);
	printed = 0;
	hexa.zeros = 0;
	if (flag.point && precision > len)
		hexa.zeros = precision - len;
	hexa.total = hexa.zeros + len;
	if (flag.hashtag && n != 0)
		hexa.total += 2;
	printed += ft_flagminus(flag, hexa, n, width);
	printed += ft_flagzero(flag, hexa, n, width);
	printed += ft_noflag(flag, hexa, n, width);
	free(hexa.prefix);
	free(hexa.num_char);
	return (printed);
}
