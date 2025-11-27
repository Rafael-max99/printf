/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typevoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:35 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 19:51:09 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nullptr(t_format *format)
{
	(*format).ints.len = 5;
	if ((*format).flags.minus)
	{
		ft_putstr("(nil)");
		(*format).logic.printed += (*format).ints.len;
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		ft_putstr("(nil)");
		(*format).logic.printed += (*format).ints.len;
	}
	return ((*format).logic.printed);
}

int	ft_typevoid(t_format *format)
{
	size_t	ptr;

	ptr = (size_t)(*format).type.ptr;
	if (ptr == 0)
		return (ft_nullptr(format));
	(*format).type.str = ft_hexa(ptr);
	(*format).ints.len = ft_strlen((*format).type.str) + 2;
	if ((*format).flags.minus)
	{
		ft_putstr("0x");
		ft_putstr((*format).type.str);
		(*format).logic.printed += (*format).ints.len;
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		ft_putstr("0x");
		ft_putstr((*format).type.str);
		(*format).logic.printed += (*format).ints.len;
	}
	free((*format).type.str);
	return ((*format).logic.printed);
}
