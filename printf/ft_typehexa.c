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

static int	ft_flagminus(t_format *format)
{
	if ((*format).flags.minus)
	{
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			(*format).logic.printed += 2;
		}
		(*format).logic.printed += ft_padding((*format).hexa.zeros, 0, '0');
		ft_putstr((*format).hexa.num_char);
		(*format).logic.printed += ft_strlen((*format).hexa.num_char);
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).hexa.total, ' ');
	}
	return ((*format).logic.printed);
}

static int	ft_flagzero(t_format *format)
{
	if ((*format).flags.zero && !(*format).logic.point)
	{
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			(*format).logic.printed += ft_strlen((*format).hexa.prefix);
		}
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).hexa.total, '0');
		ft_putstr((*format).hexa.num_char);
		(*format).logic.printed += ft_strlen((*format).hexa.num_char);
	}
	return ((*format).logic.printed);
}

static int	ft_noflag(t_format *format)
{
	if (!(*format).flags.minus && !((*format).flags.zero && !(*format).logic.point))
	{
		(*format).logic.printed += ft_padding((*format).logic.width, (*format).hexa.total, ' ');
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			(*format).logic.printed += ft_strlen((*format).hexa.prefix);
		}
		(*format).logic.printed += ft_padding((*format).hexa.zeros, 0, '0');
		ft_putstr((*format).hexa.num_char);
		(*format).logic.printed += ft_strlen((*format).hexa.num_char);
	}
	return ((*format).logic.printed);
}

int	ft_typehexa(t_format *format, char type)
{
	(*format).hexa.num_char = ft_hexa((*format).type.nu);
	(*format).hexa.prefix = ft_prefix(type, (*format).hexa.num_char);
	(*format).ints.len = ft_strlen((*format).hexa.num_char);
	(*format).hexa.zeros = 0;
	if ((*format).logic.point && (*format).logic.precision > (*format).ints.len)
		(*format).hexa.zeros = (*format).logic.precision - (*format).ints.len;
	(*format).hexa.total = (*format).hexa.zeros + (*format).ints.len;
	if ((*format).flags.hashtag && (*format).type.nu != 0)
		(*format).hexa.total += 2;
	(*format).logic.printed += ft_flagminus(format);
	(*format).logic.printed += ft_flagzero(format);
	(*format).logic.printed += ft_noflag(format);
	free((*format).hexa.prefix);
	free((*format).hexa.num_char);
	return ((*format).logic.printed);
}
