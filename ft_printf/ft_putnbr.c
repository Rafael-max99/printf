/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:55 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 01:34:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n)
{
	int		pos;
	long	nb;
	char	num_char[20];

	pos = 0;
	nb = n;
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		num_char[pos++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (pos-- > 0)
		ft_putchar(num_char[pos]);
}
