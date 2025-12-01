/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:02 by rlauren           #+#    #+#             */
/*   Updated: 2025/12/01 01:38:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int				count;
	int				pos;
	unsigned long	nb;
	char			num_char[20];

	count = 0;
	pos = 0;
	nb = n;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		num_char[pos++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (pos-- > 0)
		count += ft_putchar(num_char[pos]);
	return (count);
}
