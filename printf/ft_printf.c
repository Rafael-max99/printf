#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hashtag;
	int	point;
}		t_flags;

typedef struct	s_types
{
	char	type;
	int	width;
}		t_types;

t_flags	ft_resetflags(void)
{
	t_flags	f;

	f.minus = 0;
	f.zero = 0;
	f.plus = 0;
	f.space = 0;
	f.hashtag = 0;
	f.point = 0;

	return (f);
}

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_toupper(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 'a' && str[x] <= 'z')
			str[x] -= 32;
		x++;
	}
}

void    ft_putnbr(int n)
{
        int             x;
        long    nb;
        char    num_char[20];

        x = 0;
        nb = n;
        if (nb == 0)
		ft_putchar('0');
        while (nb > 0)
        {
                num_char[x++] = (nb % 10) + '0';
                nb /= 10;
        }
        while (x-- > 0)
                ft_putchar(num_char[x]);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_hexa(size_t num)
{
	int	pos;
	int	x;
	char	*hex;
	char	num_char[17];
	char	*result;

	pos = 0;
	x = 0;
	hex = "0123456789abcdef";
	if (num == 0)
	{
		result = malloc(2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	while (num != 0)
	{
		num_char[pos++] = hex[num%16];
		num = num/16;
	}
	result = malloc(pos + 1);
	if (!result)
		return (NULL);
	while (x < pos)
	{
		result[x] = num_char[pos - 1 - x];
		x++;
	}
	result[x] = '\0';
	return (result);
}

void	ft_print_types(t_flags flag, void *value, char type, int width, int precision)
{
	char	c;
	char	*str;
	size_t	ptr;
	int	len;

	if (type == 'c')
	{
		c = *(char *)value;
		if (flag.minus)
		{
			ft_putchar(c);
			while (width-- > 1)
				ft_putchar(' ');
		}
		else
		{
			while (width-- > 1)
				ft_putchar(' ');
			ft_putchar(c);
		}
	}
	else if (type == 's')
	{
		str = (char *)value;
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		if (flag.point && precision < len)
			len = precision;
		if (flag.minus)
                {
                        write (1, str, len);
                        while (width-- > len)
                                ft_putchar(' ');
                }
                else
                {
                        while (width-- > len)
                                ft_putchar(' ');
                        write (1, str, len);
                }
	}
	else if (type == 'p')
	{
		ptr = (size_t)value;
		str = ft_hexa(ptr);
		len = ft_strlen(str) + 2;
		if (flag.minus)
		{
			ft_putstr("0x");
			ft_putstr(str);
		while (width-- > len)
			ft_putchar(' ');
		}
		else
		{
			while (width-- > len)
				ft_putchar(' ');
			ft_putstr("0x");
			ft_putstr(str);
		}
		free(str);
	}
}

void	ft_print_un_int(t_flags flag, unsigned int n, int width, int precision)
{
	int	len;
	int	zeros;
	int	total;

	len = ft_numlen(n);
	zeros = 0;
	total = len;
	if (n == 0 && flag.point && precision == 0)
		len = 0;
	if (flag.point && precision > len)
	{
		zeros = precision - len;
		flag.zero = 0;
		total = zeros + len;
	}
	if (flag.minus)
	{
		while (zeros-- > 0)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(n);
		while (width-- > total)
			ft_putchar(' ');
	}
	else if (flag.zero && !flag.point)
	{
		while (width-- > total)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(n);
	}
	else
	{
		while (width-- > total)
			ft_putchar(' ');
		while (zeros-- > 0)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(n);
	}
}

void	ft_print_hexa(t_flags flag, unsigned int n, char type, int width, int precision)
{
	int     len;
	char	str[3];
	char	*num_char;
	int	zeros;
	int	total;

	num_char = ft_hexa(n);
	str[0] = '0';
	if (type == 'x')
		str[1] = 'x';
	else if (type == 'X')
	{
		str[1] = 'X';
		ft_toupper(num_char);
	}
	str[2] = '\0';
	len = ft_strlen(num_char);
	zeros = 0;
	if (flag.point && precision > len)
		zeros = precision - len;
	total = zeros + len;
	if (flag.hashtag && n != 0)
		total += 2;
        if (flag.minus)
        {
		if (flag.hashtag && n != 0)
			ft_putstr(str);
		while (zeros-- > 0)
			ft_putchar('0');
                ft_putstr(num_char);
                while (width-- > total)
                        ft_putchar(' ');
        }
        else if (flag.zero && !flag.point)
        {
		if (flag.hashtag && n != 0)
		{
			ft_putstr(str);
			total -= 2;
		}
                while (width-- > total)
                        ft_putchar('0');
                ft_putstr(num_char);
        }
        else
        {
                while (width-- > total)
			ft_putchar(' ');
		if (flag.hashtag && n != 0)
			ft_putstr(str);
		while (zeros-- > 0)
			ft_putchar('0');
                ft_putstr(num_char);
        }
	free(num_char);
}

void	ft_print_ints(t_flags flag, int n, int width, int precision)
{
	int	len;
	long	nb;
	int	zeros;
	int	total;

	nb = n;
	zeros = 0;
	if (nb < 0)
		nb = -nb;
	len = ft_numlen(nb);
	if (nb == 0 && flag.point && precision == 0)
		len = 0;
	total = len;
	if (flag.point && precision > len)
	{
		zeros = precision - len;
		flag.zero = 0;
		total = zeros + len;
	}
	if (flag.plus && n >= 0)
		total++;
	else if (flag.space && n >= 0)
		total++;
	if (flag.minus)
	{
		if (n < 0)
			ft_putchar('-');
		else if (flag.plus)
			ft_putchar('+');
		else if (flag.space)
			ft_putchar(' ');
		while (zeros-- > 0)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(nb);
		while (width-- > total)
			ft_putchar(' ');
	}
	else if (flag.zero && !flag.point)
	{
		if (n < 0)
			ft_putchar('-');
		else if (flag.plus)
			ft_putchar('+');
		else if (flag.space)
			ft_putchar(' ');
		while (width-- > total)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(nb);
	}
	else
	{
		while (width-- > total)
			ft_putchar(' ');
		if (n < 0)
			ft_putchar('-');
		else if (flag.plus)
			ft_putchar('+');
		else if (flag.space)
			ft_putchar(' ');
		while (zeros-- > 0)
			ft_putchar('0');
		if (len > 0)
			ft_putnbr(nb);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int	ct;
	char	*str;
	char	c;
	int	n;
	unsigned int	nu;
	void	*ptr;
	int	width;
	int	num_len;
	t_flags	flags;
	int	precision;

	va_start(args, fmt);
	ct = 0;

	while (fmt[ct])
	{
		if (fmt[ct] == '%')
		{
			flags = ft_resetflags();
			width = 0;
			ct++;
			while (fmt[ct] == '-' || fmt[ct] == '0' || fmt[ct] == '+' || fmt[ct] == ' ' || fmt[ct] == '#')
			{
				if (fmt[ct] == '-')
					flags.minus = 1;
				if (fmt[ct] == '0')
					flags.zero = 1;
				if (fmt[ct] == '+')
					flags.plus = 1;
				if (fmt[ct] == ' ')
					flags.space = 1;
				if (fmt[ct] == '#')
					flags.hashtag = 1;
				ct++;
			}
			while (fmt[ct] >= '0' && fmt[ct] <= '9')
			{
				width = (width * 10) + (fmt[ct] - '0');
				ct++;
			}
			precision = -1;
			if (fmt[ct] == '.')
			{
				flags.point = 1;
				ct++;
				precision = 0;
				while (fmt[ct] >= '0' && fmt[ct] <= '9')
				{
					precision = (precision * 10) + (fmt[ct] - '0');
					ct++;
				}
			}
			if (fmt[ct] == 'c')
			{
				c = va_arg(args, int);
				ft_typechar(flags, c, width);
			}
			else if (fmt[ct] == 's')
			{
				str = va_arg(args, char *);
				ft_typestring(flags, str, width, precision);
			}
			else if (fmt[ct] == 'p')
			{
				ptr = va_arg(args, void *);
				ft_typevoid(flags, ptr, width);
			}
			else if (fmt[ct] == 'd' || fmt[ct] == 'i')
			{
				n = va_arg(args, int);
				ft_print_ints(flags, n, width, precision);
			}
			else if (fmt[ct] == 'u')
			{
				nu = va_arg(args, unsigned int);
				ft_typeunsint(flags, nu, width, precision);
			}
			else if (fmt[ct] == 'x' || fmt[ct] == 'X')
			{
				nu = va_arg(args, unsigned int);
				ft_print_hexa(flags, nu, fmt[ct], width, precision);
			}
			else if (fmt[ct] == '%')
				ft_putchar('%');
			else
				ft_putchar(fmt[ct]);
		}
		else
			ft_putchar(fmt[ct]);
		ct++;
	}
	va_end(args);
	return (ct);
}

int	main(void)
{
	int	x = 42;
	int	*ptr = &x;

	ft_printf("%p\n", ptr);
	ft_printf("%0#10x\n", 42);
	ft_printf("%+.5u\n", 42);
	ft_printf("%0.d", 0);
	return (0);
}
