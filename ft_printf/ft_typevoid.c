/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typevoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:35 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 12:58:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nullptr(t_format *format)
{
	int	count;

	count = 0;
	(*format).ints.len = 5;
	if ((*format).flags.minus)
	{
		ft_putstr("(nil)");
		count += (*format).ints.len;
		count += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		count += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		ft_putstr("(nil)");
		count += (*format).ints.len;
	}
	return (count);
}

static void	ft_putprefix(t_format *format)
{
	ft_putstr("0x");
	ft_putstr((*format).type.str);
}

int	ft_typevoid(t_format *format)
{
	size_t	ptr;
	int		count;

	count = 0;
	ptr = (size_t)(*format).type.ptr;
	if (ptr == 0)
		return (ft_nullptr(format));
	(*format).type.str = ft_hexa(ptr);
	(*format).ints.len = ft_strlen((*format).type.str) + 2;
	if ((*format).flags.minus)
	{
		ft_putprefix(format);
		count += (*format).ints.len;
		count += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		count += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		ft_putprefix(format);
		count += (*format).ints.len;
	}
	free((*format).type.str);
	return (count);
}
