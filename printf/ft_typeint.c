#include "libftprintf.h"

static int	ft_putsign(t_flags flag, int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (1);
	}
	else if (flag.plus)
	{
		ft_putchar('+');
		return (1);
	}
	else if (flag.space)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

static int	ft_flagminus(t_flags flag, t_ints num, int n, int width)
{
	int	printed;

	printed	= 0;
	if (flag.minus)
	{
		printed += ft_putsign(flag, n);
		printed += ft_padding(num.zeros, 0, '0');
		if (num.len > 0)
		{
			ft_putnbr(num.nb);
			printed += num.len;
		}
		printed += ft_padding(width, num.total, ' ');
	}
		return (printed);
}

static int	ft_flagzero(t_flags flag, t_ints num, int n, int width)
{
	int	printed;

	printed = 0;
	if (flag.zero && !flag.point)
	{
		printed += ft_putsign(flag, n);
		printed += ft_padding(width, num.total, '0');
		if (num.len > 0)
		{
			ft_putnbr(num.nb);
			printed += num.len;
		}
	}
	return (printed);
}

static int	ft_noflag(t_flags flag, t_ints num, int n, int width)
{
	int	printed;

	printed = 0;
	if (!flag.minus && !(flag.zero && !flag.point))
	{
		printed += ft_padding(width, num.total, ' ');
		printed += ft_putsign(flag, n);
		printed += ft_padding(num.zeros, 0, '0');
		if (num.len > 0)
		{
			ft_putnbr(num.nb);
			printed += num.len;
		}
	}
	return (printed);
}

int	ft_typeint(t_flags flag, int n, int width, int precision)
{
	t_ints	num;
	int	printed;

	num.nb = n;
	num.zeros = 0;
	printed = 0;
	num.nb = ft_negnum(num.nb);
	num.len = ft_numlen(num.nb);
	if (num.nb == 0 && flag.point && precision == 0)
		num.len = 0;
	num.total = num.len;
	if (flag.point && precision > num.len)
	{
		num.zeros = precision - num.len;
		flag.zero = 0;
		num.total = num.zeros + num.len;
	}
	if (flag.plus && n >= 0)
		num.total++;
	else if (flag.space && n >= 0)
		num.total++;
	printed += ft_flagminus(flag, num, n, width);
	printed += ft_flagzero(flag, num, n, width);
	printed += ft_noflag(flag, num, n, width);
	return (printed);
}
