/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:45 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:50:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding(int width, int n, char c)
{
	int	printed;

	printed = 0;
	while (width-- > n)
	{
		ft_putchar(c);
		printed++;
	}
	return (printed);
}
