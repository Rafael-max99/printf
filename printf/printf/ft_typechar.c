/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:15 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 18:58:16 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_typechar(t_format *format)
{
	(*format).logic.printed += 1;
	if ((*format).flags.minus)
	{
		ft_putchar((*format).type.c);
		(*format).logic.printed += ft_padding((*format).logic.width, 1, ' ');
	}
	else
	{
		(*format).logic.printed += ft_padding((*format).logic.width, 1, ' ');
		ft_putchar((*format).type.c);
	}
	return ((*format).logic.printed);
}
