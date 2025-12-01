/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:25 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 13:00:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nullstr(t_format *format)
{
	if (!(*format).type.str && (*format).logic.point
		&& (*format).logic.precision < 6)
		(*format).ints.len = 0;
	else
	{
		if (!(*format).type.str)
			(*format).type.str = "(null)";
		(*format).ints.len = ft_strlen((*format).type.str);
		if ((*format).logic.point
			&& (*format).logic.precision < (*format).ints.len)
			(*format).ints.len = (*format).logic.precision;
	}
}

int	ft_typestring(t_format *format)
{
	int	count;

	count = 0;
	ft_nullstr(format);
	if ((*format).flags.minus)
	{
		if ((*format).ints.len > 0)
			write (1, (*format).type.str, (*format).ints.len);
		count += (*format).ints.len;
		count += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width,
				(*format).ints.len, ' ');
		if ((*format).ints.len > 0)
			write (1, (*format).type.str, (*format).ints.len);
		count += (*format).ints.len;
	}
	return (count);
}
