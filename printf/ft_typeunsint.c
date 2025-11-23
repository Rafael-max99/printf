#include "libftprintf.h"

static int	ft_flagminus(t_flags flag, t_ints num, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (flag.minus)
	{
		printed += ft_padding(num.zeros, 0, '0');
		if (num.len > 0)
		{
			ft_putnbr(n);
			printed += num.len;
		}
		printed += ft_padding(width, num.total, ' ');
	}
	return (printed);
}

static int	ft_flagzero(t_flags flag, t_ints num, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (flag.zero && !flag.point)
	{
		printed += ft_padding(width, num.total, '0');
		if (num.len > 0)
		{
			ft_putnbr(n);
			printed += num.len;
		}
	}
	return (printed);
}

static int	ft_noflag(t_flags flag, t_ints num, unsigned int n, int width)
{
	int	printed;

	printed = 0;
	if (!flag.minus && !(flag.zero && !flag.point))
	{
		printed += ft_padding(width, num.total, ' ');
		printed += ft_padding(num.zeros, 0, '0');
		if (num.len > 0)
		{
			ft_putnbr(n);
			printed += num.len;
		}
	}
	return (printed);
}

int	ft_typeunsint(t_flags flag, unsigned int n, int width, int precision)
{
	t_ints	num;
	int	printed;

	num.len = ft_numlen(n);
	num.zeros = 0;
	printed = 0;
	if (n == 0 && flag.point && precision == 0)
		num.len = 0;
	num.total = num.len;
	if (flag.point && precision > num.len)
	{
		num.zeros = precision - num.len;
		flag.zero = 0;
		num.total = num.zeros + num.len;
	}
	printed += ft_flagminus(flag, num, n, width);
	printed += ft_flagzero(flag, num, n, width);
	printed += ft_noflag(flag, num, n, width);
	return (printed);
}
