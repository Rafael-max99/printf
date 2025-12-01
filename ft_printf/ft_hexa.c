/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:57:35 by rlauren           #+#    #+#             */
/*   Updated: 2025/11/30 14:50:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_transformnum(size_t num)
{
	int		count;
	int		pos;
	char	*hex;
	char	num_char[17];
	char	*result;

	count = 0;
	pos = 0;
	hex = "0123456789abcdef";
	while (num != 0)
	{
		num_char[count++] = hex[num % 16];
		num = num / 16;
	}
	result = malloc(count + 1);
	if (!result)
		return (NULL);
	while (pos < count)
	{
		result[pos] = num_char[count - 1 - pos];
		pos++;
	}
	result[pos] = '\0';
	return (result);
}

char	*ft_hexa(size_t num)
{
	char	*result;

	if (num == 0)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	return (ft_transformnum(num));
}
