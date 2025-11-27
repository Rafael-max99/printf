/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauren <rlauren@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:45 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/27 18:57:46 by rlauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
