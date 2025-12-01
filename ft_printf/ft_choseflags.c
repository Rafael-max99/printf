/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choseflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:28 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:50:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choseflags(const char *fmt, t_format *format)
{
	while (fmt[(*format).logic.ct] == '-' || fmt[(*format).logic.ct] == '0'
		|| fmt[(*format).logic.ct] == '+' || fmt[(*format).logic.ct] == ' '
		|| fmt[(*format).logic.ct] == '#')
	{
		if (fmt[(*format).logic.ct] == '-')
			(*format).flags.minus = 1;
		if (fmt[(*format).logic.ct] == '0')
			(*format).flags.zero = 1;
		if (fmt[(*format).logic.ct] == '+')
			(*format).flags.plus = 1;
		if (fmt[(*format).logic.ct] == ' ')
			(*format).flags.space = 1;
		if (fmt[(*format).logic.ct] == '#')
			(*format).flags.hashtag = 1;
		(*format).logic.ct++;
	}
	return ((*format).logic.ct);
}
