/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:15 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:49:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typechar(t_format *format)
{
	int	count;

	count = 0;
	count += 1;
	if ((*format).flags.minus)
	{
		ft_putchar((*format).type.c);
		count += ft_padding((*format).logic.width, 1, ' ');
	}
	else
	{
		count += ft_padding((*format).logic.width, 1, ' ');
		ft_putchar((*format).type.c);
	}
	return (count);
}
