/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choseflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:28 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 19:11:48 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
