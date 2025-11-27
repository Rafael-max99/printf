/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:25 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 20:26:58 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_nullstring(t_format *format)
{
	if (!(*format).type.str)
	{
		if ((*format).logic.point)
			(*format).ints.len = 0;
		else
			(*format).type.str = "(null)";
	}
}

int	ft_typestring(t_format *format)
{
	ft_nullstring(format);
	if ((*format).type.str)
		(*format).ints.len = ft_strlen((*format).type.str);
	if ((*format).logic.point && (*format).logic.precision < (*format).ints.len)
		(*format).ints.len = (*format).logic.precision;
	if ((*format).flags.minus)
	{
		write (1, (*format).type.str, (*format).ints.len);
		(*format).logic.printed += (*format).ints.len;
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		write (1, (*format).type.str, (*format).ints.len);
		(*format).logic.printed += (*format).ints.len;
	}
	return ((*format).logic.printed);
}
