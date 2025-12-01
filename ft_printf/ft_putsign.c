/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:25:19 by marvin            #+#    #+#             */
/*   Updated: 2025/12/01 13:25:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsign(t_format *format)
{
	if ((*format).type.n < 0)
	{
		ft_putchar('-');
		return (1);
	}
	else if ((*format).flags.plus)
	{
		ft_putchar('+');
		return (1);
	}
	else if ((*format).flags.space)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}
