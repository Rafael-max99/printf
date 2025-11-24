#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
}		t_flags;

t_flags	ft_resetflags(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_toupper(char *str);
void	ft_putnbr(int n);
int	ft_strlen(char *str);
int	ft_numlen(int num);

typedef struct	s_hexa
{
	int	total;
	int	zeros;
	char	*prefix;
	char	*num_char;
}		t_hexa;

typedef struct	s_ints
{
	int	len;
	long	nb;
	int	zeros;
	int	total;
}		t_ints;

typedef struct	s_logic
{
	int	width;
	int	precision;
	int	point;
	int	ct;
	int	printed;
}		t_logic;

typedef struct	s_type
{
	int	c;
	char	*str;
	void	*ptr;
	int	n;
	unsigned int	nu;
}		t_type;

typedef struct	s_format
{
	t_flags	flags;
	t_logic	logic;
	t_hexa	hexa;
	t_ints	ints;
	t_type	type;
}		t_format;

#endif