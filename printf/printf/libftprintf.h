/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:49 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 20:33:32 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hashtag;
}		t_flags;

typedef struct s_hexa
{
	int		total;
	int		zeros;
	char	*prefix;
	char	*num_char;
}		t_hexa;

typedef struct s_ints
{
	int		len;
	long	nb;
	int		zeros;
	int		total;
}		t_ints;

typedef struct s_logic
{
	int	width;
	int	precision;
	int	point;
	int	ct;
	int	printed;
}		t_logic;

typedef struct s_type
{
	int				c;
	char			*str;
	void			*ptr;
	int				n;
	unsigned int	nu;
}		t_type;

typedef struct s_format
{
	t_flags	flags;
	t_logic	logic;
	t_hexa	hexa;
	t_ints	ints;
	t_type	type;
}		t_format;

t_flags	ft_resetflags(void);
t_logic	ft_resetlogic(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_toupper(char *str);
void	ft_putnbr(long n);
void	ft_putunbr(unsigned int n);
int		ft_strlen(char *str);
int		ft_numlen(long num);
char	*ft_hexa(size_t num);
int		ft_typechar(t_format *format);
int		ft_typestring(t_format *format);
int		ft_typevoid(t_format *format);
int		ft_typeint(t_format *format);
int		ft_typeunsint(t_format *format);
int		ft_typehexa(t_format *format, char type);
int		ft_printf(const char *fmt, ...);
int		ft_padding(int width, int n, char c);
long	ft_negnum(long n);
int		ft_choseflags(const char *fmt, t_format *format);

#endif