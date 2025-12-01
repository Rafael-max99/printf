/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeunsint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:32 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flagminus(t_format *format)
{
	int	count;

	count = 0;
	if ((*format).flags.minus)
	{
		count += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
			count += ft_putunbr((*format).type.nu);
		count += ft_padding((*format).logic.width,
				(*format).ints.total, ' ');
	}
	return (count);
}

static int	ft_flagzero(t_format *format)
{
	int	count;

	count = 0;
	if ((*format).flags.zero && !(*format).logic.point)
	{
		count += ft_padding((*format).logic.width,
				(*format).ints.total, '0');
		if ((*format).ints.len > 0)
			count += ft_putunbr((*format).type.nu);
	}
	return (count);
}

static int	ft_noflag(t_format *format)
{
	int	count;

	count = 0;
	if (!(*format).flags.minus && !((*format).flags.zero
			&& !(*format).logic.point))
	{
		count += ft_padding((*format).logic.width,
				(*format).ints.total, ' ');
		count += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
			count += ft_putunbr((*format).type.nu);
	}
	return (count);
}

int	ft_typeunsint(t_format *format)
{
	int	count;

	count = 0;
	(*format).ints.len = ft_numlen((*format).type.nu);
	(*format).ints.zeros = 0;
	if ((*format).type.nu == 0 && (*format).logic.point
		&& (*format).logic.precision == 0)
		(*format).ints.len = 0;
	(*format).ints.total = (*format).ints.len;
	if ((*format).logic.point && (*format).logic.precision > (*format).ints.len)
	{
		(*format).ints.zeros = (*format).logic.precision - (*format).ints.len;
		(*format).flags.zero = 0;
		(*format).ints.total = (*format).ints.zeros + (*format).ints.len;
	}
	if ((*format).flags.minus)
	{
		(*format).flags.zero = 0;
		count += ft_flagminus(format);
	}
	else if ((*format).flags.zero && !(*format).logic.point)
		count += ft_flagzero(format);
	else
		count += ft_noflag(format);
	return (count);
}
