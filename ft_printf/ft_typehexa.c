/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:18 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 13:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flagminus(t_format *format)
{
	int	count;

	count = 0;
	if ((*format).flags.minus)
	{
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			count += 2;
		}
		count += ft_padding((*format).hexa.zeros, 0, '0');
		ft_putstr((*format).hexa.num_char);
		count += ft_strlen((*format).hexa.num_char);
		count += ft_padding((*format).logic.width,
				(*format).hexa.total, ' ');
	}
	return (count);
}

static int	ft_flagzero(t_format *format)
{
	int	count;

	count = 0;
	if ((*format).flags.zero && !(*format).logic.point)
	{
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			count += ft_strlen((*format).hexa.prefix);
		}
		count += ft_padding((*format).logic.width,
				(*format).hexa.total, '0');
		ft_putstr((*format).hexa.num_char);
		count += ft_strlen((*format).hexa.num_char);
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
				(*format).hexa.total, ' ');
		if ((*format).flags.hashtag && (*format).type.nu != 0)
		{
			ft_putstr((*format).hexa.prefix);
			count += ft_strlen((*format).hexa.prefix);
		}
		count += ft_padding((*format).hexa.zeros, 0, '0');
		ft_putstr((*format).hexa.num_char);
		count += ft_strlen((*format).hexa.num_char);
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

int	ft_typehexa(t_format *format, char type)
{
	int	count;

	count = 0;
	if ((*format).type.nu == 0 && (*format).logic.point
		&& (*format).logic.precision == 0)
	{
		if ((*format).logic.width > 0)
			count += ft_padding((*format).logic.width,
					0, ' ');
		return (count);
	}
	(*format).hexa.num_char = ft_hexa((*format).type.nu);
	(*format).hexa.prefix = ft_prefix(type, (*format).hexa.num_char);
	(*format).ints.len = ft_strlen((*format).hexa.num_char);
	(*format).hexa.zeros = 0;
	if ((*format).logic.point && (*format).logic.precision > (*format).ints.len)
		(*format).hexa.zeros = (*format).logic.precision - (*format).ints.len;
	(*format).hexa.total = (*format).hexa.zeros + (*format).ints.len;
	if ((*format).flags.hashtag && (*format).type.nu != 0)
		(*format).hexa.total += 2;
	count += ft_choseflag(format);
	free((*format).hexa.prefix);
	free((*format).hexa.num_char);
	return (count);
}
