#include "libftprintf.h"

t_flags	ft_resetflags(void)
{
	t_flags	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.hashtag = 0;

	return (flag);
}

t_logic	ft_resetlogic(void)
{
	t_logic	logic;

	logic.width = 0;
	logic.precision = -1;
	logic.point = 0;
	logic.ct = 0;
	logic.printed = 0;

	return (logic);
}

static int	ft_choseflags(const char *fmt, t_format *format)
{
	while (fmt[(*format).logic.ct] == '-' || fmt[(*format).logic.ct] == '0' || fmt[(*format).logic.ct] == '+' 
			|| fmt[(*format).logic.ct] == ' ' || fmt[(*format).logic.ct] == '#')
	{
		if (fmt[(*format).logic.ct] == '-')
			(*format).flags.minus = 1;
		if (fmt[(*format).logic.ct] == '0')
			(*format).flags.zero = 1;
		if (fmt[(*format).logic.ct] == '+')
			(*format).flags.plus = 1;
		if (fmt[(*format).logic.ct] == ' ')
			(*format).flags.space = 1;
		if (fmt[(*format).logic.ct] == '#')
			(*format).flags.hashtag = 1;
		(*format).logic.ct++;
	}
	return ((*format).logic.ct);
}

static int	ft_widthprecision(const char *fmt, t_format *format)
{
	(*format).logic.width = 0;
	(*format).logic.precision = -1;
	(*format).logic.point = 0;
	while (fmt[(*format).logic.ct] >= '0' && fmt[(*format).logic.ct] <= '9')
	{
		(*format).logic.width = ((*format).logic.width * 10) + (fmt[(*format).logic.ct] - '0');
		(*format).logic.ct++;
	}
	if (fmt[(*format).logic.ct] == '.')
	{
		(*format).logic.point = 1;
		(*format).logic.ct++;
		(*format).logic.precision = 0;
		while (fmt[(*format).logic.ct] >= '0' && fmt[(*format).logic.ct] <= '9')
		{
			(*format).logic.precision = ((*format).logic.precision * 10) + (fmt[(*format).logic.ct] - '0');
			(*format).logic.ct++;
		}
	}
	return ((*format).logic.ct);
}

static int	ft_chosetype1(char *fmt, va_list *args, t_format *format)
{
	if (fmt[(*format).logic.ct] == 'c')
	{
		(*format).type.c = va_arg(*args, int);
		(*format).logic.printed += ft_typechar((*format).flags, (*format).type.c, (*format).logic.width);
		return ((*format).logic.ct + 1);
	}
	else if (fmt[(*format).logic.ct] == 's')
	{
		(*format).type.str = va_arg(*args, char *);
		(*format).logic.printed += ft_typestring((*format).flags, (*format).type.str, (*format).logic.width, (*format).logic.precision);
		return ((*format).logic.ct + 1);
	}
	else if (fmt[(*format).logic.ct] == 'p')
	{
		(*format).type.ptr = va_arg(*args, void *);
		(*format).logic.printed += ft_typevoid((*format).flags, (*format).type.ptr, (*format).logic.width);
		return ((*format).logic.ct + 1);
	}
	else if (fmt[(*format).logic.ct] == 'd' || fmt[(*format).logic.ct] == 'i')
	{
		(*format).type.n = va_arg(*args, int);
		(*format).logic.printed += ft_typeint((*format).flags, (*format).type.n, (*format).logic.width, (*format).logic.precision);
		return ((*format).logic.ct + 1);
	}
	return (0);
}

static int	ft_chosetype2(char *fmt, va_list *args, t_format *format)
{
	if (fmt[(*format).logic.ct] == 'u')
	{
		(*format).type.nu = va_arg(*args, unsigned int);
		(*format).logic.printed += ft_typeunsint((*format).flags, (*format).type.nu, (*format).logic.width, (*format).logic.precision);
		return ((*format).logic.ct + 1);
	}
	else if (fmt[(*format).logic.ct] == 'x' || fmt[(*format).logic.ct] == 'X')
	{
		(*format).type.nu = va_arg(*args, unsigned int);
		(*format).logic.printed += ft_typehexa((*format).flags, (*format).type.nu, (*format).logic.width, (*format).logic.precision);
		return ((*format).logic.ct + 1);
	}
	else if (fmt[(*format).logic.ct] == '%')
	{
		ft_putchar('%');
		(*format).logic.printed++;
		return ((*format).logic.ct + 1);
	}
	else
	{
		ft_putchar(fmt[(*format).logic.ct]);
		(*format).logic.printed++;
		return ((*format).logic.ct + 1);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_format	format;
	int	temp_ct;

	format.flags = ft_resetflags();
	format.logic = ft_resetlogic();
	va_start(args, fmt);
	while (fmt[(*format).logic.ct])
	{
		if (fmt[(*format).logic.ct] == '%')
		{
			(*format).logic.ct++;
			(*format).logic.ct = ft_choseflags(fmt, &format);
			(*format).logic.ct = ft_widthprecision(fmt, &format);
			temp_ct = ft_chosetype1(fmt, &args, &format);
			if (temp_ct)
				(*format).logic.ct = temp_ct;
			else
				(*format).logic.ct = ft_chosetype2(fmt, &args, &format);
		}
		else
		{
			ft_putchar(fmt[(*format).logic.ct++]);
			(*format).logic.printed++;
		}
	}
	va_end(args);
	return ((*format).logic.printed);
}
