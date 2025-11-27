/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:02 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 20:38:26 by rlaurean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunbr(unsigned int n)
{
	int	pos;
	unsigned long	nb;
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
