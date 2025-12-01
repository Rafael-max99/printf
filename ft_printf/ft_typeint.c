/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:22 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 13:27:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flagminus(t_format *format)
{
	int	count;

	count = 0;
	if ((*format).flags.minus)
	{
		count += ft_putsign(format);
		count += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).ints.nb);
			count += (*format).ints.len;
		}
		count += ft_padding((*format).logic.width,
				(*format).ints.total, ' ');
	}
	return (count);
}

static int	ft_flagzero(t_format *format)
{
	int	pad_zeros;
	int	count;

	count = 0;
	if ((*format).flags.zero && !(*format).logic.point)
	{
		count += ft_putsign(format);
		pad_zeros = (*format).logic.width - (*format).ints.total;
		if (pad_zeros > 0)
			count += ft_padding(pad_zeros, 0, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).ints.nb);
			count += (*format).ints.len;
		}
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
		count += ft_putsign(format);
		count += ft_padding((*format).ints.zeros, 0, '0');
		if ((*format).ints.len > 0)
		{
			ft_putnbr((*format).ints.nb);
			count += (*format).ints.len;
		}
	}
	return (count);
}

static int	ft_choseflag(t_format *format)
{
	int	count;

	count = 0;
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

int	ft_typeint(t_format *format)
{
	int	count;

	count = 0;
	(*format).ints.nb = (*format).type.n;
	(*format).ints.zeros = 0;
	(*format).ints.nb = ft_negnum((*format).ints.nb);
	(*format).ints.len = ft_numlen((*format).ints.nb);
	if ((*format).ints.nb == 0 && (*format).logic.point
		&& (*format).logic.precision == 0)
		(*format).ints.len = 0;
	(*format).ints.total = (*format).ints.len;
	if ((*format).logic.point && (*format).logic.precision > (*format).ints.len)
	{
		(*format).ints.zeros = (*format).logic.precision - (*format).ints.len;
		(*format).flags.zero = 0;
		(*format).ints.total = (*format).ints.zeros + (*format).ints.len;
	}
	if ((*format).type.n < 0)
		(*format).ints.total++;
	if ((*format).flags.plus && (*format).type.n >= 0)
		(*format).ints.total++;
	else if ((*format).flags.space && (*format).type.n >= 0)
		(*format).ints.total++;
	count += ft_choseflag(format);
	return (count);
}
